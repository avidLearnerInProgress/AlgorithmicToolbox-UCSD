#include <iostream>

int get_fibonacci_last_digit_fast(int n){
	if(n<=1) return n;
	
	int i=2;
	long long a=0, b=1, c=0;
	while(i <= n){
		c = (a + b)% 10;
		a = b % 10;
		b = c % 10;
		i++;	
	}
	return b;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
