#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cassert>

using namespace std;
//http://www.cplusplus.com/forum/lounge/32041/
//100! = 9332621544394415268169923885626670049071596826438162146859296389521759999322991
//5608941463976156518286253697920827223758251185210916864000000000000000000000000
class BigInt {
	private:
	string buffer;
	public:
	BigInt(){buffer="0";}
	BigInt(int i);
	BigInt(string s);
	void set_buffer(string s);
	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator=(const BigInt& that);
	friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator+=(const BigInt& that);
	friend BigInt operator-(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator-=(const BigInt& that);
	friend BigInt operator*(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator*=(const BigInt& that);
	friend BigInt operator/(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator/=(const BigInt& i);
	friend BigInt operator%(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator%=(const BigInt& i);
	friend bool operator==(const BigInt& lhs, const BigInt& rhs);
	friend bool operator!=(const BigInt& lhs, const BigInt& rhs);
	friend bool operator>(const BigInt& lhs, const BigInt& rhs);
	friend bool operator>=(const BigInt& lhs, const BigInt& rhs);
	friend bool operator<(const BigInt& lhs, const BigInt& rhs);
	friend bool operator<=(const BigInt& lhs, const BigInt& rhs);
	friend ostream& operator<<(ostream& os, const BigInt& i);
	friend istream& operator>>(istream& is, BigInt& i);
	string to_string() const;
};

BigInt::BigInt(int i){
	do{
		 char c = (i%10) + '0';
		 buffer += c;
	} while((i = i/10) != 0);

	size_t n = buffer.size();
	if(n > 1 && buffer[n-1] == '0') buffer.erase(n-1);
	//cout<<"in cons:"<<buffer<<endl;
	//reverse(buffer.begin(), buffer.end());
}

BigInt::BigInt(string s) {
	reverse(s.begin(), s.end());
	buffer = s;
}
void BigInt::set_buffer(string s){
	reverse(s.begin(), s.end());
	buffer = s;
}

string BigInt::to_string() const{
	string str = buffer;
	reverse(str.begin(), str.end());
	return str;
}

ostream& operator<<(ostream& os, const BigInt& bi){
		os<<bi.to_string();
	return os;
}

istream& operator>>(istream& is, BigInt& bi){
		string s;
		is>>s;
		bi.set_buffer(s);
	return is;
}

BigInt& BigInt::operator=(const BigInt& that){
	if(this != &that){
		string s = that.to_string();
		this->set_buffer(s);
	}
	return *this;
}

BigInt operator+(const BigInt &lhs, const BigInt &rhs){
	BigInt r = lhs;
	return r += rhs;
}

BigInt& BigInt::operator+=(const BigInt &that){
	size_t this_size = this->buffer.size();
	size_t that_size = that.buffer.size();
	size_t n = max(this_size, that_size);
	int carry = 0;
	for(size_t i = 0; i < n || carry; i++){
		if(i >= this_size) this->buffer +='0';
		int this_digit = (i < this_size)?this->buffer[i] - '0':0;
		int that_digit = (i < that_size)?that.buffer[i] - '0':0;
		int sum = this_digit + that_digit + carry;
		this->buffer[i] = (sum%10) + '0';
		carry = sum/10;
	}
	return *this;
}

BigInt operator*(BigInt &lhs, BigInt &rhs){
	BigInt r = lhs;
	return r *= rhs;
}


BigInt& BigInt::operator*=(const BigInt &rhs){
	BigInt temp = *this;
	for(BigInt i = 0; i + 1 < rhs; ++i){
		*this += temp;
	}
	return *this;
}

BigInt& BigInt::operator++(){
	*this += 1;
	return *this;
}

BigInt BigInt::operator++(int){
	BigInt result = *this;
	*this += 1;
	return result;
}

bool operator<(const BigInt& lhs, const BigInt& rhs){
	int lhs_size = lhs.buffer.size();
	int rhs_size = rhs.buffer.size();
	int n = max(lhs_size, rhs_size);
	for(int i = n-1; i >= 0; i--){
		char this_digit = (i < lhs_size)?lhs.buffer[i]:'0';
		char that_digit = (i < rhs_size)?rhs.buffer[i]:'0';
		if(this_digit < that_digit) return true;
		else if(this_digit > that_digit) return false;
	}
	return false;
}

bool operator==(const BigInt& lhs, const BigInt& rhs){
	size_t lhs_size = lhs.buffer.size();
	size_t rhs_size = rhs.buffer.size();
	size_t n = max(lhs_size, rhs_size);
	for(size_t i = 0; i < n; i++){
		char this_digit = (i < lhs_size)?lhs.buffer[i]:'0';
		char that_digit = (i < rhs_size)?rhs.buffer[i]:'0';
		if(this_digit != that_digit) return false;
	}
	return true;
}

bool operator<=(const BigInt& lhs, const BigInt& rhs){
	return lhs < rhs || lhs == rhs;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs){
	return !(lhs == rhs);
}

BigInt factorial(int n){
	BigInt result = 1;
	//cout<<"init:"<<result<<endl;
	for(int i = 1; i <= n; ++i){
		result *= i;
	//cout<<"in:"<<result<<endl;
	}
	return result;
}
int factorial_int(int n){
	int result = 1;

	for(int i = 1; i <= n; ++i){
		result *= i;
	}
	return result;
}


int main(){
	int n = 100;
	const string f100 = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
	assert(factorial(100).to_string() == f100);
	//cout<<factorial(100).to_string()<<endl;
	cout<<factorial(n)<<endl;
	cout<<factorial_int(n)<<endl;
	//BigInt i = 100;
	//cin>>i;
	//cout<<i<<endl;
	return 0;
}
