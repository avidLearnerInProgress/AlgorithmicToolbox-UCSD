#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
 		
int partition(int W, vector<int> w) {
  //write your code here
  int rsize = w.size() +1 ;
  int csize = W+1;  
  vector< vector<int> > knapsack(rsize, vector<int> (csize, 0)); 

  for(int i=1;i<rsize;i++)
  { 
    for(int j=1;j<csize;j++)
    {
      if(i ==0 || j == 0) knapsack[i][j] = 0;
      else if(w[i-1] > j)
      {
        knapsack[i][j] = knapsack[i-1][j];
      }
      else
      {
        int rem = j - w[i-1];
        knapsack[i][j] = std::max((w[i-1]+knapsack[i-1][rem]),knapsack[i-1][j]);
      }
      
    }
  }
  int count = 0;
  for(int i=0;i<rsize;i++)
  {
      if(knapsack[i][csize-1] == W)
      count++;
  }
  if(count >= 3)
  return 1;
  else
  return 0;
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
  std::cin >> w[i];
  }
  
  int sum = 0;
  sort(w.begin(),w.end());
  for(int i=0;i<w.size();i++)
  {
      sum += w[i];
  }
  
  if(sum%3 !=0)
  {std::cout << 0 << '\n';}
  else
  {
    std::cout << partition(sum/3, w) << '\n';  
  }
  
}


