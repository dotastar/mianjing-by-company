#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
 
 
// BEGIN CUT HERE
typedef long long int64;
// END CUT HERE
 
class TreeUnionDiv2
{
public:

    int maximumCycles(vector <string> tree1, vector <string> tree2, int K) 
    {
		int n = tree1.size();
		const int inf = 100;
		// g[i][j] is the shortest distance from i to j
		vector<vector<int> > g1(n, vector<int>(n, inf));
		vector<vector<int> > g2(n, vector<int>(n, inf));
        int ret = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j) {
				if(tree1[i][j] == 'X') g1[i][j] = 1;
				if(tree2[i][j] == 'X') g2[i][j] = 1;
				if(i == j) {
					g1[i][j] = 0;
					g2[i][j] = 0;
				}
			}
		}
		//Floyd¨CWarshall algorithm
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j){
					if(g1[i][k] + g1[k][j] < g1[i][j]) g1[i][j] = g1[i][k] + g1[k][j];
					if(g2[i][k] + g2[k][j] < g2[i][j]) g2[i][j] = g2[i][k] + g2[k][j];
				}

		//for every permutation
		vector<int> p(n);
		for(int i = 0; i < n; ++i){
			p[i] = i; 
		}
		do{
			int count = 0;
			for(int i = 0; i < n; ++i){
				for(int j = i+1; j < n; ++j){
					if(g1[i][j] + g2[p[i]][p[j]] + 2 == K) ++count;
				}
			}
			ret = max(ret, count);
		}while(next_permutation(p.begin(), p.end()));
        return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-X",
 "X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X",
 "X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 1; verify_case(0, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 2; verify_case(1, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(2, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 5; verify_case(3, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 17; verify_case(4, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TreeUnionDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
