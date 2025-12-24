#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll x;

    cin >> n >> x;

    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i]; 
    }


    int start = 0;
    ll count = 0;

    ll c = 0;
    for(int end = 0; end < n; end++){
        c += nums[end];
        
        while(c >= x  && start <= end){
            if(c == x){
                count++;
            }
            c -= nums[start];
            start++;
        }
    }

    cout << count;
}

