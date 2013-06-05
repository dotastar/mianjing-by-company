void swap_p(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void swap_r(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
void swap_cool(int &v1, int &v2) {
  v1 = v1 ^ v2;
  v2 = v1 ^ v2;
  v1 = v1 ^ v2;
}

int main() {
}
