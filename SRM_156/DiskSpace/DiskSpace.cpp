#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class DiskSpace {
    public:
    int minDrives(vector<int> used, vector<int> total) {
        return 0;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {300,525,110}, {350,600,115} }, {2} },
    { { {1,200,200,199,200,200}, {1000,200,200,200,200,200} }, {1} },
    { { {750,800,850,900,950}, {800,850,900,950,1000} }, {5} },
    { { {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49}, {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50} }, {49} },
    { { {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385}, {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906} }, {6} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(DiskSpace* x) {
            return x->minDrives(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DiskSpace>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1456872243, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
