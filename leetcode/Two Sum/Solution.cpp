#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctime>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
         vector<int> v;
         for(int i = 0; i < numbers.size(); i++){
           m[target - numbers[i]] = i; 
         }
         for(int i = 0; i < numbers.size(); i++){
           if(m.count(numbers[i]) == 1) {
             v.push_back(min(i+1, m[numbers[i]] + 1));
             v.push_back(max(i+1, m[numbers[i]] + 1));
             return v;
           }
         }
         return v;
    }
};

bool read_int(string &input, string::size_type &pos, int &output) {
  string::size_type found = input.find_first_not_of("0123456789", pos);
  if(found == pos) return false;
  string str_number = input.substr(pos, found - pos);
  stringstream ss(str_number);
  ss>>output;
  pos = found;
  return true;
}
bool read_int_vector(string &input, string::size_type &pos, vector<int> &output) {
  if(input[pos] != '[') {
    cerr<<"vector should begin with ["<<endl;
    return false;
  } else pos++;
  while(1) {
    int t = 0;
    if(read_int(input, pos, t)) {
      output.push_back(t);
    } else {
    }
    if(input[pos] == ',') pos++;
    else if(input[pos] == ']') {
      pos++;
      return true;
    } else {
      cerr<<"invalid char in array"<<endl;
      return false;
    }
  }
  return true;
}
int main() {
  Solution s;
  string line;
  clock_t t;
  t = clock();
  while(!cin.eof()) {
    getline(cin, line);
    string::size_type pos = line.find_first_not_of(" \t");
    if(pos == string::npos) continue;
    vector<int> numbers;
    int target = 0;
    if(!read_int_vector(line, pos, numbers)) {
      cerr<<"data format error"<<endl;
      continue;
    }
    if(line.substr(pos,2) != ", ") {
      cerr<<"data format error"<<endl;
      continue;
    } else pos += 2;
    if(!read_int(line, pos, target))  {
      cerr<<"data format error"<<endl;
      continue;
    }
    int a = 0;
    pos += 1;
    read_int(line, pos, a);
    pos += 2;
    read_int(line, pos, a);
    pos += 1;
    int i1 = 0;
    read_int(line, pos, i1);
    pos += 2;
    int i2 = 0;
    read_int(line, pos, i2);

    vector<int> pair;
    pair = s.twoSum(numbers, target);
    if(pair[0] != i1 || pair[1] != i2) {
      cerr<<"output are: "<<pair[0]<<","<<pair[1]<<endl;
      cerr<<"expect are: "<<i1<<","<<i2<<endl;
      cerr<<"test case is: "<<endl<<line<<endl;
      break;
    } else {
      //cout<<"test case pass: "<<endl<<line<<endl;
    }
  }
  t = clock() - t;
  cout<<t<<endl;
  cout<<CLOCKS_PER_SEC<<endl;
  //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  
}
