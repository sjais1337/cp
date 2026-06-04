#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& nums){
  int n = nums.size();
  for(int i = 0; i < n; i++){
    int min_el = INT_MAX;
    int min_index = 0;
    for(int j = i; j < n; j++){
      if(min(nums[j], min_el) != min_el){
        min_el = min(nums[j], min_el); 
        min_index = j;
      }
    }
    int temp = nums[i];
    nums[i] = min_el;
    nums[min_index] = temp;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> nums(n);
  
  for(int i =0; i < n; i++){
    cin >> nums[i];
  }

  selection_sort(nums);

  for(int i = 0; i< n; i++){
    cout << nums[i] << endl;
  }
}
