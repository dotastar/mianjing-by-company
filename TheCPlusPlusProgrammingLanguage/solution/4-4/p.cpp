#include <iostream>

using namespace std;

const char char_table[] = "abcdefghijklmnopqrstuvwxyz0123456789`~!@#$%^&*()-=_+[]\\{}|;':\",./<>?";
int main(){
  for(int i = 0; i < sizeof(char_table) -1 ; ++i){
    cout<<char_table[i]<<"->"<<int(char_table[i])<<endl;
  }
  for(int i = 0; i < sizeof(char_table) - 1; ++i){
    cout<<char_table[i]<<"->"<<hex<<int(char_table[i])<<endl;
  }

}
