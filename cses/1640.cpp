#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Random retard bullshit here, just ignore it

    int n; 
    ll x;

    cin >> n >> x;

    vector<ll> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int start = 0, end = 1;

    while((start != n-1) && (end != n-1)){
        int s = nums[start], e = nums[end];
        if(s+e > x){
            end++;
        }else if (s+e < x){
            start++;
        }else{
            if(start == end) continue;
            cout << start + 1 << " " << end + 1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

