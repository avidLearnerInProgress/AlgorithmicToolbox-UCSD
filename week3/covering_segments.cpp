#include <bits/stdc++.h>

using namespace std;

vector<int> optimal_points(vector<pair<int,int>> &segments) {
  vector<int> points;

  std::sort(segments.begin(),segments.end(),[](const pair<int,int> &left, const pair<int,int> &right){
      return left.second < right.second;
    });
  int leftestright = segments[0].second;
  points.push_back(leftestright);

  for (size_t i = 0; i < segments.size(); ++i) {
    if(segments[i].first<=leftestright){
      continue;
    }
    else{
      leftestright = segments[i].second;
      points.push_back(leftestright);
    }
  }
  return points;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> segments(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}


