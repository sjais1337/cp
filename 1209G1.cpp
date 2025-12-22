#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct num{
    int number;
    int start; 
    int end;
    int freq;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<int,num> info;

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    set<int> temp(nums.begin(), nums.end());
    for(int x: temp){
        num t;
        t.number = x;
        t.start = abs(find(nums.begin(), nums.end(), x) - nums.begin());
        t.end = abs(find(nums.rbegin(), nums.rend(), x) - nums.rend());
        t.freq = count(nums.begin(), nums.end(), x);
    }
    
}

