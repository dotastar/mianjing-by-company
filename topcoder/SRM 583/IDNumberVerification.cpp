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
 
 
 
class IDNumberVerification
{
public:
    string verify(string id, vector <string> regionCodes) 
    {
		//verify region code
		string  region_code_part = id.substr(0, 6);
		int n = regionCodes.size();
		int i = 0;
		for(; i < n; ++i){
			if(regionCodes[i] == region_code_part)
				break;
		}
		if( i == n) return "Invalid";
		//verify birthday
		string  birthday_code_part = id.substr(6, 8);
		/*if(birthday_code_part < "19000101" || birthday_code_part > "20111231")
			return "Invalid";*/
		string year_str = birthday_code_part.substr(0, 4);
		int year = stoi (year_str);
		string month_str = birthday_code_part.substr(4, 2);
		int month = stoi (month_str);
		string day_str = birthday_code_part.substr(6, 2);
		int day = stoi (day_str);
		if(year < 1900 || year > 2011) return "Invalid";
		if(month <= 0 || month > 12) return "Invalid";
		bool is_leap_year = (year%4 == 0 && year%100 != 0) || (year % 400 == 0);
		int days[2][12] = {{31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31}, 
							{31, 29, 31, 30, 31, 30,31, 31, 30, 31, 30, 31}};
		if(is_leap_year) {
			if(day <= 0 || day > days[1][month-1]) return "Invalid";
		} else {
			if(day <= 0 || day > days[0][month-1]) return "Invalid";
		}
		// verify sequential code
		string sequential_code_part = id.substr(14, 3);
		if(sequential_code_part == "000") return "Invalid";
		int sum = 0;
		for(i = 0; i < 17; ++i){
			sum += id[i] - '0';
			sum *= 2;
		}
		sum += (id[17] == 'X')? 10:(id[17] - '0');
		if( sum % 11 != 1) return "Invalid"; 
		// man or not
		if(id[16] % 2 != 0) return "Male";
		else return "Female";
	}		

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
