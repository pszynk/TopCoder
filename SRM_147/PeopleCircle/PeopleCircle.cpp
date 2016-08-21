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

class PeopleCircle {
    public:
    string order(int numMales, int numFemales, int K) {
        return "";
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
    { { 5, 3, 2 }, {"MFMFMFMM"} },
    { { 7, 3, 1 }, {"FFFMMMMMMM"} },
    { { 25, 25, 1000 }, {"MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"} },
    { { 5, 5, 3 }, {"MFFMMFFMFM"} },
    { { 1, 0, 245 }, {"M"} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;

        string run(PeopleCircle* x) {
            return x->order(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<PeopleCircle>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            350, 1456864493, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
