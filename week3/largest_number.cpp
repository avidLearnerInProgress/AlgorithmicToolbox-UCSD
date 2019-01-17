#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool is_greater(string n1, string n2) {
  string a = n1 + n2;
  string b = n2 + n1;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] > b[i]) {
      return true;
    } else if (a[i] < b[i]) {
      return false;
    }
  }
  return false;
}
string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  
  std::sort(a.begin(),a.end(),is_greater);
  std::cout << largest_number(a);
}
