#include <iostream>
#include <limits>
#include <typeinfo>

using namespace std;

template<typename T>
void type_info_print() {
	cout<<typeid(T).name()<<":range is ("<<numeric_limits<T>::min()<<","<<numeric_limits<T>::max()<<")"<<endl;
}

int main(){
	type_info_print<char>();
	type_info_print<short>();
        type_info_print<int>();
	type_info_print<long>();
	type_info_print<float>();
	type_info_print<double>();
	type_info_print<long double>();
	type_info_print<unsigned>();

//	cout<<"char min->"<<numeric_limits<char>::min()<<endl;
//	cout<<"char max->"<<numeric_limits<char>::max()<<endl;
//	cout<<"short min->"<<numeric_limits<short>::min()<<endl;
//	cout<<"short max->"<<numeric_limits<short>::max()<<endl;
//	cout<<"int min->"<<numeric_limits<long>::min()<<endl;
//	cout<<"int max->"<<numeric_limits<long>::max()<<endl;
//	cout<<"float min->"<<numeric_limits<float>::min()<<endl;
//	cout<<"float max->"<<numeric_limits<float>::max()<<endl;
//	cout<<"double min->"<<numeric_limits<double>::min()<<endl;
//	cout<<"double max->"<<numeric_limits<double>::max()<<endl;
//	cout<<"long double min->"<<numeric_limits<long double>::min()<<endl;
//	cout<<"long double max->"<<numeric_limits<long double>::max()<<endl;
//	cout<<"unsigned min->"<<numeric_limits<unsigned>::min()<<endl;
//	cout<<"unsigned max->"<<numeric_limits<unsigned>::max()<<endl;
}
