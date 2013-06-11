#include <cstring>
#include <cassert>

using namespace std;

char* cat(const char *s1, const char *s2) {
  assert(s1 && s2);
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);
  char* s3 = new char[len1+len2+1];
  strcpy(s3, s1);
  strcpy(s3+len1, s2);
  return s3;
}
int main() {
  
}
