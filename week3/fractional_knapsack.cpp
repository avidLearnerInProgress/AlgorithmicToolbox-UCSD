#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define f first
#define s second

using std::vector;
using std::pair;
using std::make_pair;


class Item{
    public:
    int value, weight;
    Item(int v, int w){
        value = v;
        weight = w;
    }
    
    Item(){}
};

bool cmp(struct Item A, struct Item B){
    return (double)A.value/A.weight > (double)B.value/B.weight;
}

double get_optimal_value(int capacity, vector<Item> items) {
    
    std::sort(items.begin(), items.end(), cmp);
    int n = items.size();
    int curr_weight = 0;
    double curr_value = 0.0;
    
    for(int i=0 ;i<n ;i++){
        
        if(curr_weight + items[i].weight <= capacity){
            curr_weight += items[i].weight;
            curr_value += items[i].value;
        }
        else{
            int remain = capacity - curr_weight;
            curr_value += items[i].value * ((float)remain / items[i].weight);
            break;
        }
    }
    return curr_value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  int weight, value;
  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    std::cin>>value>>weight;
    items[i] = Item(value, weight);
  }
  double optimal_value = get_optimal_value(capacity, items);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
