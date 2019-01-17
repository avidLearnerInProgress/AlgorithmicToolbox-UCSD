#include <iostream>
#define ll long long
using namespace std;

//239 1000
//F2015 mod 3 = F7 mod 3 = 1  --> 2015 = 251*8 + 7
/*
2 3 
4 5
6 7
8 9
10 11
500 501

*/

ll get_pasino_period(ll m){
	ll a = 0, b = 1;
	ll c = a + b;

	for(int i=0; i<m*m; i++){
		c = (a+b) % m;
		a = b;
		b = c;
		if(a == 0 && b == 1) return i+1; 
	}
}
ll fibonacci(ll n, ll m){
	ll remain = n % get_pasino_period(m);
	ll f = 0, s = 1;
	ll res = remain;
	//if(n<=1) return 1;
	
	for(int i=1; i<remain; i++){
		res = (f + s) % m;
		f = s;
		s = res;
	}
	
	return res % m;
}

int main()
{
    ll N , M;
    cin >> N >> M;
    cout << fibonacci(N , M) << endl;
}
