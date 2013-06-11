#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string name;
  double value = 0;
  map<string, int> map_count;
  map<string, double> map_sum;
  int total_count = 0;
  double total_sum = 0;
  while(cin>>name){
    cin>>value;
    cout<<"get "<<name<<":"<<value<<endl;
    map_count[name]++;
    map_sum[name] += value;
    total_count++;
    cout<<"-total count:"<<total_count<<endl;
    total_sum += value;
    cout<<"-total sum:"<<total_sum<<endl;
  }
  for(map<string, int>::iterator i = map_count.begin(); i!= map_count.end(); ++i) {
    cout<<"name:"<<i->first<<" sum:"<<map_sum[i->first]<<" means:"<<map_sum[i->first]/map_count[i->first]<<endl;
  }
  cout<<"total sum:"<<total_sum<<" total means:"<<total_sum/total_count<<endl;
  return 0;
}
