(defvar topcoder-buffer "*topcoder*")

(defvar topcoder-release-compile-command "make release"
  "topcoder project release binary compilation command")

(defvar topcoder-debug-compile-command "make debug"
  "topcoder project debug binary compilation command")

(defvar topcoder-clean-command "make clean"
  "clean topcoder project command")

(defvar topcoder-run-command "./release.out"
  "topcoder project release binary compilation command")

(defvar topcoder-debug-command "gdb -i=mi debug.out"
  "topcoder project release binary compilation command")

(defvar topcoder-build-and-run t
  "")

(defvar topcoder-build-and-debug t
  "")

(defun topcoder/clean ()
  "cleaning topcoder project"
  (interactive)
  (shell-command topcoder-clean-command)
  )

(defun topcoder/build-release ()
  (interactive)
  (compile topcoder-release-compile-command))

(defun topcoder/run ()
  "cleaning topcoder project"
  (interactive)
  ;; make release
  ;; if make succesful run binary
  ;;  if binary succesful just print success in minibuffer
  ;;  else move to the end of test buffer
  (let ((buffer topcoder-buffer))
    (if (shell-command topcoder-run-command buffer)
        (progn
          (topcoder//end-of-buffer-in-windows buffer)
          (run-with-timer 2 nil
                          (lambda (buf)
                            (bury-buffer buf)
                            (winner-undo)
                            (message "all test passed X-D"))
                          buffer)
          )
      (progn
        (message "test failed :-O")
        (topcoder//end-of-buffer-in-windows buffer)))))

(defun topcoder/build-debug ()
  (interactive)
  (compile topcoder-debug-compile-command))

(defun topcoder/debug ()
  (interactive)
  (gdb "gdb -i=mi debug.out"))



(defun topcoder//compile-finish-hook (buffer string)
  (if (and
       (string-match "compilation" (buffer-name buffer))
       (string-match "finished" string))
      (if (not
           (with-current-buffer buffer
             (goto-char (point-min))
             (search-forward "warning" nil t)))
          ;; compilation successful
          (progn
            (message "build successufl!")
            (run-with-timer 1 nil
                            (lambda (buf)
                              ;; close compilation buffer
                              (bury-buffer buf)
                              ;; return focus to previous window
                              (winner-undo)
                              ;; run/debug
                              (topcoder//execute-after-build buf))
                            buffer))
        ;; compilation have warnings - ask if should run/debug
        (if (y-or-n-p "Compilation finshed with warnings :-| ...execute run/debug anyway?")
            (progn
              ;; close compilation buffer
              (bury-buffer buffer)
              ;; return focus to previous window
              (winner-undo)
              ;; run/debug
              (topcoder//execute-after-build buffer))
          )
        )
    ;; compilation failed - do nothing
    (message "Compilation failed :-("))
  )

(defun topcoder//execute-after-build (buffer)
  (with-current-buffer buffer
    (goto-char (point-min))
    (cond
     ((and
       topcoder-build-and-run
       (re-search-forward (concat "^" topcoder-release-compile-command) nil t))
      (topcoder/run))
     ((and
       topcoder-build-and-debug
       (re-search-forward (concat "^" topcoder-debug-compile-command) nil t))
      (topcoder/debug))
     (t
      (message "unknown build"))
     )
    )
  )

(defun topcoder//end-of-buffer-in-windows (buffer)
  (dolist (win (get-buffer-window-list buffer nil t))
    (unless (eq (selected-window) win)
      (with-selected-window win
        (end-of-buffer)))))


(defun topcoder//config-output-window ()
  (add-to-list 'display-buffer-alist
               `(,(lambda (buffer action)
                    (string= topcoder-buffer buffer))
                 (display-buffer-in-side-window)
                 (inhibit-same-window . t)
                 (window-height . 0.4))))


(define-minor-mode topcoder-mode
  "Mode for solving TopCoder provlems"
  :lighter " ₸"
  :global nil
  :group 'topcoder
  (if topcoder-mode
      (progn
        (setq compilation-finish-functions 'topcoder//compile-finish-hook)
        (topcoder//config-output-window)

        (defadvice display-message-or-buffer (before ansi-color activate)
          "Process ANSI color codes in shell output."
          (let ((buf (ad-get-arg 0)))
            (and (bufferp buf)
                 (string= (buffer-name buf) topcoder-buffer)
                 (with-current-buffer buf
                   (ansi-color-apply-on-region (point-min) (point-max))))))

        (spacemacs|define-micro-state topcoder
          :doc "[r]elase [d]ebug"
          :disable-evil-leader t
          :use-minibuffer t
          :bindings
          ("r" topcoder/build-release)
          ("d" topcoder/build-debug)
          )

        (defalias 'topcoder/menu 'spacemacs/topcoder-micro-state)
        (evil-leader/set-key
          "or" 'topcoder/build-release
          "od" 'topcoder/build-debug
          "om" 'topcoder/menu)
        )))


;;;###autoload
(add-hook 'c-mode-hook 'topcoder-mode)

(provide 'topcoder)
