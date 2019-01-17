#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int bsearch(const vector<int> &a, int x, int left, int right){
	if((right - left) == 1) return -1;
	int mid = (right + left ) / 2;
	if(x == a[mid]) return mid;
	if(x < a[mid]) return bsearch(a, x, left, mid);
	else return bsearch(a, x, mid, right); 
	
}

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size(); 
    //write your code here
  	if(x<a.front() || x>a.back())return -1;
  	
  	else if(x==a.front()) return left;
  	
  	else if(x==a.back()) return right - 1;
  	
  	else return bsearch(a, x, left, right);
   //return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
