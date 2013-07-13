#include <iostream>
#include <string>

using namespace std;
void reverse_string(string& s, int low, int high){
  for(int i = 0 ; i <(high - low + 1)/2; ++i){
    swap(s[low+i], s[high-i]);
  }
}
void reverse_text(string& s){
  int n = s.size();
  reverse_string(s, 0, n-1);
  bool used = true;
  int low = 0;
  int high = 0;
  int i = 0;
  for(; i < n; ++i){
    if(s[i] == ' ' && used){
      high = i - 1;
      reverse_string(s, low, high);
      used = false;
    } else if(s[i] != ' ' && !used){
      low = i;
      used = true;
    }
  }
  high = i - 1;
  reverse_string(s, low, high);
  used = false;
}

void rotate_string(string& s, int n){
  int string_size = s.size();
  n %= string_size;
  reverse_string(s, 0, string_size - 1);
  reverse_string(s, 0, string_size - n -1);
  reverse_string(s, string_size - n, string_size - 1);  
}
int main() {
  string s1 = "I am a student.";
  reverse_text(s1);
  cout<<s1<<endl;
  cout<<"====="<<endl;
  string s2 = "abcdefg";
  rotate_string(s2, 2);
  cout<<s2<<endl;
  //find_sum2(15);
  return 0;
}

