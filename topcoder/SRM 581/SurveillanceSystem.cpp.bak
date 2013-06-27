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
 
class SurveillanceSystem
{
public:
    string getContainerInfo(string containers, vector <int> reports, int L) 
    {
		int n = containers.size();//number of containers
		int m = reports.size(); // number of cameras
		//index is the container number monitored by camera, 
		//value is this kind of camera number
		vector<int> reports_counts(L+1, 0); 
		for(int i = 0; i < m ; ++i) {
			reports_counts[reports[i]]++;
		}
		vector<int> camera(n-L+1, 0);
		//index is the camara postion
		//value is the container number monitored by the camera
		for(int i = 0; i < n-L+1; ++i)
			for(int j = i; j < i+L; ++j)
				if(containers[j] == 'X') camera[i]++ ;
		string ret(n, '-');
		for(int i = 0; i < n; ++i){
			//possible reports_counts if skip i
			vector<int> skip_counts(L+1, 0);
			for(int j = 0; j <n-L+1; ++j)
				if(j > i || j+L-1 < i)
					skip_counts[camera[j]]++;
			bool can_skip = true;
			for(int j = 0; j < L+1; ++j)
				if(skip_counts[j] < reports_counts[j]) {
					can_skip = false;
					break;
				}

			if(!can_skip) {
				ret[i] = '+';
			} else {
				bool can_monitor = false;
				for(int j = max(0, i-(L-1)); j <= min(n-L, i); ++j)
					if(reports_counts[camera[j]] > 0){
						can_monitor = true;
						break;
					}
				if(can_monitor) ret[i] = '?';
				else ret[i] = '-';
			}
		}
        return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        SurveillanceSystem ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE