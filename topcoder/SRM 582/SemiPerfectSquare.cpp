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
 
 
 
class SemiPerfectSquare
{
public:
    string check(int N) 
    {
		int lim = (int)sqrt(N);
		for(int a = 1; a < lim; ++a){
			for(int b = a+1; b <= lim;++b){
				if(a*b*b == N) return "Yes";
			}
		}
        return "No";
    }
    

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
