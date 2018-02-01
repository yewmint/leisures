// gcd(a, b) = ax + by
int extend_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int q = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return q;
}