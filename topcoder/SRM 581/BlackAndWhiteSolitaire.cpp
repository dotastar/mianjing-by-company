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
 
 
// BEGIN CUT HERE
typedef long long int64;
// END CUT HERE
 
class BlackAndWhiteSolitaire
{
public:
	void flip(string &cardfront, int i){
		if(cardfront[i] == 'W') cardfront[i] = 'B';
		else cardfront[i] = 'W';
	}

    int minimumTurns(string cardFront) 
    {
		int n = cardFront.size();
		if (n <=1 ) return 0;
		int flip_count_keep_0 = 0;
		
		string cardFront0(cardFront);
		string cardFront1(cardFront);

		//keep 0
		for(int i = 1; i < n; ++i) {
			if(cardFront0[i] == cardFront0[i-1]) {
				flip(cardFront0, i);
				++flip_count_keep_0;
			}
		}
		//flip 0
		int flip_count_keep_1 = 1;
		flip(cardFront1, 0);
		for(int i = 1; i < n; ++i) {
			if(cardFront1[i] == cardFront1[i-1]) {
				flip(cardFront1, i);
				++flip_count_keep_1;
			}
		}
        return min(flip_count_keep_0, flip_count_keep_1);
        }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBBW"; int Arg1 = 1; verify_case(0, Arg1, minimumTurns(Arg0)); }
	void test_case_1() { string Arg0 = "WBWBW"; int Arg1 = 0; verify_case(1, Arg1, minimumTurns(Arg0)); }
	void test_case_2() { string Arg0 = "WWWWWWWWW"; int Arg1 = 4; verify_case(2, Arg1, minimumTurns(Arg0)); }
	void test_case_3() { string Arg0 = "BBWBWWBWBWWBBBWBWBWBBWBBW"; int Arg1 = 10; verify_case(3, Arg1, minimumTurns(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        BlackAndWhiteSolitaire ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE


