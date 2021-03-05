int f() {
  return 2;
}

int main() {
  int *p = 0;
  if (p == 0) {
    int a = f();
    p = &a;
  }
  return *p;
}