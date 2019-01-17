#include <iostream>

long long gcd_naive(long long a, long long b) {
  if(b == 0 || a == 0) return a;
  else return gcd_naive(b, a%b);
}


long long lcm_naive(long long a, long long b) {
  return (a*b)/ gcd_naive(a,b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

/*
14159572 63967072 
Your output: -527892768 
Correct output: 226436590403296 (Time used: 0.01/1.00, memory used: 9867264/536870912.)
*/