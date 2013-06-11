#include <cstdio>
#include <cstddef>
#include <assert.h>

using namespace std;

size_t strlen(char const* s) {
  assert(s);
  size_t len = 0;
  while(s[len])
    ++len;
  return len;
}

char* strcpy(char *t, char const *s) {
  assert(t && s);
  while(*t++ = *s++);
  return t;
}

int strcmp(char const *s, char const *t) {
  assert(s && t);
  do {
    int diff = *s - *t;
    if(diff) return diff;
    s++;
    t++;
  } while(*s && *t);
  return *s - *t;
}

int main() {
  return 0;
}
