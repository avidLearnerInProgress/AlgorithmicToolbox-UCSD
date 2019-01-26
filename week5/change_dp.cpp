#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int get_change(int m) {
  //write your code here
  int res;
  vector<int> a = {1, 3, 4};
  int dp[m + 1];
  dp[0] = 0;
  
  for(int i=1; i<=m; i++)dp[i] = INT_MAX;
  for(int i=1; i<=m; i++){
  	for(int j=0; j<a.size(); j++){
  		if(i>=a[j]){
  			res = dp[i - a[j]];
  			if(res != INT_MAX && res + 1 < dp[i]){
  				dp[i] = res + 1;
			  }
  			
		  }
	  }
  }
  if(dp[m] == INT_MAX) return -1;
	  else return dp[m];

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
