#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <numeric>

#define ll long long
using std::cin;
using std::cout;

//These imports suck.. we can use <bits/stdc++.h>
//ucsd :|

ll get_fibonacci_fast(ll n){
//This is better than stupid naive and dp algo..
    
    ll F1 = 0, F2 = 1, F;
    if(n <= 1) return n;
    
    for(int i = 2 ; i <= n ; i++){
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}

ll get_fibonacci_last_digit_fast(ll n){
//Storing only last digit of the fib  
   
   ll F1 = 0, F2 = 1, F;
   if(n <= 1) return n;
   
   for(int i = 2; i <= n; i++){
       F = (F1 + F2) % 10;
       F1 = F2 % 10;
       F2 = F % 10;
   }
   return F;
}

ll get_pisano_period_length(ll m){
    ll a = 0, b = 1, p = a + b;
    
    for(int i = 0 ; i < m*m; i++){
        p = (a + b) % m;
        a = b;
        b = p;
        if(a == 0 && b == 1) return i + 1;
    }
}

ll get_fibonacci_huge_fast(ll n, ll m){
    
    ll remain = n % get_pisano_period_length(m);
    ll F, F1 = 0, F2 = 1;
    
    for(int i = 1; i < remain; i++){
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

ll get_fibonacci_sum_fast(ll n){
    
    ll c, f = 0, s = 1, sum = 1;
    ll norm = n % 60;
    if(norm <= 1) return norm;
    
    for(int i = 2; i <= norm; i++){
        //..
        c = f + s;
        f = s;
        s = c % 10;
        sum += s;
    }
    return sum % 10;
}
/*
ll get_fibonacci_partial_sum_fast(ll m, ll n){
    if(m > n) return 0;
    
    ll fib[n+1];
    fib[0] = 0; fib[1] = 1;
    
    for(int i = 2; i <= 60; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    //ok.. i have all numbers in series now lets repeat.
    
    m %= 60; n %= 60;
    if(n < m) n += 60;
    
    ll sum = 0;
    
    for(int i = m; i <= n; i++){
        sum += fib[i % 60];
    }
    
    return sum % 10;
}
*/

ll get_fibonacci_partial_sum_fast(ll from, ll to)
{
	ll fib[to+1];
	if(to <= 1 && from <= 1)
		return to;
		
	fib[0] = 0;
	fib[1] = 1;
	
	for(int i = 2; i <= from; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	ll sum = fib[from];
	
	for(int i = from; i <= to; i++){
		fib[i] = (fib[i-1] + fib[i-2]) % 10;
		sum = (sum + fib[i]) %10;
	}
	return sum%10;
}

int main() {
    ll n, m;
    cin >> m >> n;
    cout << get_fibonacci_partial_sum_fast(m, n) << '\n';
}
