#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, c;
    int ind1 = -1;
    int ind2 = -1;
    std::cin >> n;
    std::vector<int> numbers(n);
    long long max1 = 0;
    long long max2 = 0;
    
    for(int i=0; i< n; i++){
        std::cin>>numbers[i];
    }
    
    for(int i=0; i<n ;++i){
        if((ind1==-1) || (numbers[i]>numbers[ind1]))
            max1 = i;
    }
    
    for(int j=0; j<n ;++j){
        if((j!=max1) && ((ind2==-1)  || (numbers[j]>numbers[ind2])))
            max2 = j;
    }
    
    std::cout<<(long long)numbers[max1] * numbers[max2]<< "\n";
    return 0;
}


	
	  