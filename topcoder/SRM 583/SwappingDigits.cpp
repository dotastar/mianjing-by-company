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
 
 
 
class SwappingDigits
{
public:
    string minNumber(string num) 
    {
		if(num.empty()) return num;
		int n = num.size();
		for(int i = 0; i < n; ++i){
			int min_index = n-1;
			for(int j = n-1; j >= i; --j){
				if(i == 0 && num[j] == '0'){
					continue;
				}
				if(num[j] < num[min_index] || (i == 0 && num[min_index] == '0' && num[j] != '0')){
						min_index = j;
				}
			}
			if(num[min_index] != num[i] ){
				if( i == 0 && num[min_index] == 0){
				} else {
					swap(num[i], num[min_index]);
					return num;
				}
			}
		}
		return num;

	}    

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
