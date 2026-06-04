#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& nums){
  int n = nums.size();
  bool swapped = true;
  while(swapped){
    bool local_swapped = false;
    for(int i = 0; i < n-1; i++){
      if(nums[i] > nums[i+1]){
        local_swapped = true;
        int temp = nums[i+1];
        nums[i+1] = nums[i];
        nums[i] = temp;
      }
    } 
    swapped = local_swapped;
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
