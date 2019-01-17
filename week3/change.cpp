#include <iostream>
#include <vector>

int get_change(int m) {
  //write your code here
  int coin_no = 0;
  int denominations[3] = {10, 5, 1};
  int i=0;
  while(m>0){
  	int curr_value = m - denominations[i];
  	if(curr_value>=0){
  		m = curr_value;
  		//std::cout<<"m: "<<m<<"\t";
  		coin_no++;
  		//std::cout<<"coin: "<<coin_no<<"\n";
	}
	else
	    i++;
  }
  return coin_no;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
