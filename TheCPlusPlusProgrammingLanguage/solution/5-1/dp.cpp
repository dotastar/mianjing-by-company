#include <iostream>
#include <string>

using namespace std;


int main(){
	char c = 'a';
	char *p_char = &c;
	int a10[10] = {0,1,2,3,4,5,6,7,8,9};
	int (&ref_a10)[10] = a10;
	string (*p_str_array)[5] = 0;
	char **pp_char = &p_char;
	const int b = 10;
	const int *p_b = &b;
	int d = 11;
	int *const p_d = &d;
}
