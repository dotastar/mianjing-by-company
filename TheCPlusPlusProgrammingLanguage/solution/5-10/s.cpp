#include <iostream>
#include <string>

using namespace std;
const int month_number = 12;
const string month_name[month_number] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","July", "Aug", "Sep","Oct", "Nov", "Dec"};
void print(const string a[], const int n) {
  for(int i = 0; i < n; i++) {
    cout<<a[i]<<endl;
  }
}
int main() {
  print(month_name, month_number);
  return 0;
}
