#include <iostream>

int fibonacci_sum_fast(long long n){

  int current=0;
  int previous=0;
  int tmp=0;
  int normalize=n%60; 
  int sum=1;

  if (normalize==0) return 0;
  else if (normalize==1) return 1;
  else {
    current=1; previous=0;
    for (int i=2; i<=normalize; i++){
      tmp=current+previous;
      previous=current;
      current=tmp%10;
      sum+=current;
    }
    return sum%10;
  }

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
