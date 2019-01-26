#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack[300][10000];
int goldbars[300];
  
int main() {
  
  int n, capacity;
  cin >> capacity >> n;
  n += 1; capacity += 1;
  
  goldbars[0] = 0;
  
  for (int i = 1; i < n; i++) {
    cin >> goldbars[i];
  }
  //sort(goldbars, goldbars + n);
  
  for(int i = 0; i < n; i++){
      for(int j = 0; j < capacity; j++){
          if( i == 0 || j == 0 ){
              knapsack[i][j] = 0;
          }
          else if(j < goldbars[i]){
              knapsack[i][j] = knapsack[i - 1][j];
          }
          else{
              knapsack[i][j] = max(goldbars[i] + knapsack[i - 1][j - goldbars[i]], knapsack[i - 1][j]);
          }
      }
  }
  	cout<<knapsack[n - 1][capacity - 1];
}
