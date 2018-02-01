// a * x ≡ 1 (mod m), determine x

// O(log(a))
int invmod_a(int a, int m) {
  int x, y;
  extend_gcd(a, m, x, y);
  return (m + x % m) % m;
}

// O(log(a))
int MOD = m;
inline int pow(const int n, const int k) {  
    long long ans = 1;  
    for (long long num = n, t = k; t; num = num * num % MOD, t >>= 1) if (t & 1) ans = ans * num % MOD;  
    return ans;  
}  
inline int invmod_b(const int num) {  
    return pow(num, MOD - 2);  
}