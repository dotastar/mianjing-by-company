#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Date{
  int month;
  int day;
  int year;
};

istream& operator>>(istream &input, Date &d){
  const int bufsize = 5;
  char buf[bufsize] = {0};
  input.getline(buf,bufsize, '/');
  d.month = atoi(buf);
  input.getline(buf,bufsize, '/');
  d.day = atoi(buf);
  input>>d.year;
  return input;
}

ostream& operator<<(ostream &output, Date &d) {
  output<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
  return output;
}

Date& init(Date &d, int month, int day, int year) {
  d.month = month;
  d.day = day;
  d.year = year;
  return d;
}
  
int main() {
  Date d;
  cout<<init(d, 4, 17, 1980)<<endl;
  cin>>d;
  cout<<d<<endl;

}
