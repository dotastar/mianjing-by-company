// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndBooks.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class LittleElephantAndBooks {
public:
//    void dfs(vector<int>& pages, vector<int>& sums, int i, int n){
//        cout<<i<<endl;
//        if(i > n-1) {
//            int sum = 0;
//            for (int j = 0; j < i; ++j){
//                sum += pages[j];
//            }
//            sums.push_back(sum);
//            return;
//        }
//        for(int j = i; j < pages.size(); ++j){
//            swap(pages[i], pages[j]);
//            dfs(pages, sums,i+1, n);
//            swap(pages[i], pages[j]);
//        }
//    }
//	int getNumber(vector <int> pages, int number) {
//		//sort(pages.begin(), pages.end());
//        vector<int> sums;
//        dfs(pages, sums, 0, number);
//        sort(sums.begin(), sums.end());
//        unique(sums.begin(), sums.end());
//        copy(sums.begin(), sums.end(), ostream_iterator<int>(cout, " "));
//        return sums[1];
//        
//	}
	int getNumber(vector <int> pages, int number) {
        sort(pages.begin(), pages.end());
        swap(pages[number - 1], pages[number]);
        int sum = 0;
        for(int i = 0; i < number; ++i) {
            sum+= pages[i];
        }
        return sum;
    }
    // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();}
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {74, 7, 4, 47, 44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 58; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 1, 9, 7, 2, 8, 6, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 29; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {74, 86, 32, 13, 100, 67, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 80; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 137; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
    // END CUT HERE
    
};

// BEGIN CUT HERE
int main()
{
    LittleElephantAndBooks ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
