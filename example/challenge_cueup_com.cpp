#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

string target_str("FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");

string password1()
{
	int n = target_str.size();
	int max_n = 0;
	int max_i = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j) {
			int k = 0;
			while(i+k <= j-k && target_str[i+k] == target_str[j-k]) ++k;
			if(i+k > j-k && j-i+1 > max_n) {
				max_i = i;
				max_n = j-i+1;
			}
		}
	return target_str.substr(max_i, max_n);
}

int target_num = 227000;

int fib(int n)
{
	if(n < 2) return n;
	else return fib(n-1) + fib(n-2);
}

int isPrime(int n)
{
	for(int i = 2; i*i < n; ++i)
		if(n % i == 0) return false;
	return true;
}
int password2()
{
	int n = 0;
	for(int i = 0; i < 30; i++) {
		n = fib(i);
		if(n>target_num && isPrime(n))	break;
	}
	n += 1;
	int sum = 0;
	for(int i = 2; i*i < n; ++i)
		if(n % i == 0 && isPrime(i)) sum += i;
	return sum;
}

vector<int> target_vector;
vector<vector<int> > set_vector;

void read_file()
{
	ifstream ifs;
	ifs.open ("c:/wuyang/workspace/wypractice/interview/startup/cueup/numbers.csv", ifstream::in);
	while (ifs.good()) {
		string str;
		getline(ifs, str, ',');
		target_vector.push_back(atoi(str.c_str()));
	}
	ifs.close();
	sort(target_vector.begin(), target_vector.end());
}

void get_subset()
{
	for(auto& x : target_vector) {
		vector<vector<int> > oldset = set_vector;
		vector<int> one;
		one.push_back(x);
		set_vector.push_back(one);
		for(auto& y : oldset) {
			y.push_back(x);
			set_vector.push_back(y);
		}
	}
}

int password3()
{
	read_file();
	get_subset();
	int sum = 0;
	for(auto& v : set_vector) {
		int n = v.size();
		int set_sum = 0;
		for(int j = 0; j < n-1; j++) {
			set_sum += v[j];
		}
		if(set_sum == v[n-1]) sum++;
	}
	return sum;
}
int main(int argc, char **argv)
{
	cout<<"password1="<<password1()<<endl;
	cout<<"password2="<<password2()<<endl;
	cout<<"password3="<<password3()<<endl;
	return 0;
}
