#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_seq(int n){
	
	vector<int> dp(n + 1);
	vector<int> seq;
	//dp[0] = 0;
	if( n == 1){
	    seq.push_back(1);
	    return seq;
	}
	
	for(int i = 1; i < dp.size(); i++){
		dp[i] = dp[i - 1] + 1;
		
		if(i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if(i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}
	
	for(int i = n; i > 1; ){
		seq.push_back(i);	
		if(dp[i - 1] == dp[i] - 1) i = i - 1;
		else if(i % 2 == 0 && (dp[i/2] == dp[i] - 1)) i = i / 2;
		else if(i % 3 == 0 && (dp[i/3] == dp[i] - 1)) i = i / 3;
	}
	seq.push_back(1);
	reverse(seq.begin(), seq.end());
	return seq;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dp_seq(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
