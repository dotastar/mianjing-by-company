#include <iostream>

using namespace std;

int main() {
  const int max_length = 10;
  char input_line[max_length] = "waht?ok?";
  int quest_count = 0;
  // int i = 0;
  // while(i < max_length) {
  //   if(input_line[i] == '?') quest_count++;
  //   ++i;
  // }
  for(char *p = input_line; p < input_line + max_length; ++p)
    if(*p == '?') quest_count++;
  
  cout<<quest_count<<endl;
}
