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

class BinaryCode {
    public:
    vector<string> decode(string message) {
        return vector<string>();
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
    { { "123210122" }, { {"011100011","NONE"} } },
    { { "11" }, { {"01","10"} } },
    { { "22111" }, { {"NONE","11001"} } },
    { { "123210120" }, { {"NONE","NONE"} } },
    { { "3" }, { {"NONE","NONE"} } },
    { { "12221112222221112221111111112221111" }, { {"01101001101101001101001001001101001","10110010110110010110010010010110010"} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;

        vector<string> run(BinaryCode* x) {
            return x->decode(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<BinaryCode>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            300, 1456881283, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
