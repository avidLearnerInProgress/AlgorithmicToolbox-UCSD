#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


int most_largest(vector <int>&a, int left, int right, int m1, int m2){
	int n = right - left;
	int cnt_m1 = 0, cnt_m2 = 0;
	
	if(m1 != -1){
		for(int i = left; i < right; i++){
			if (m1 == a[i]) cnt_m1 ++;
		}
	}
	if(m2 != -1){
		for(int i = left; i < right; i++){
			if (m2 == a[i]) cnt_m2 ++;
		}
	}
	
	if(cnt_m1 > (n/2)) return m1;
	if(cnt_m2 > (n/2)) return m2;
	return -1;
}


int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    //write your code here
    int mid = left + (right - left) / 2;
    int u = get_majority_element(a, left, mid);
	int v = get_majority_element(a, mid, right);
	int majority = most_largest(a, left, right, u, v);
    return majority;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
