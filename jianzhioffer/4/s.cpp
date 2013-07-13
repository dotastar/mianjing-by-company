#include <cstdio>
#include <cstdlib>

using namespace std;

char* replaceSpace(char *str) {
  int space_num = 0;
  int non_space_num = 0;
  for(char* p = str; *p != 0; ++p){
    if(*p == ' ') ++space_num;
    else ++non_space_num;
  }
  char *result = (char *)malloc(non_space_num + 3*space_num + 1);
  int i = non_space_num + space_num - 1;
  int j = non_space_num + 3*space_num;
  result[j--] = '\0';
  while(i >= 0){
    if(str[i] == ' ') {
      result[j--] = '0';
      result[j--] = '2';
      result[j--] = '%';
    } else {
      result[j--] = str[i];
    }
    --i;
  }
  return result;
}

int main() {
  char str[] = " it is a  test! ";
  printf("[%s]->[%s]\n", str, replaceSpace(str));
  return 0;
}
