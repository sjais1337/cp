#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> N(n);

    for(int i = 0; i < n; i++){
        cin >> N[i];
    }
    
    sort(N.begin(), N.end());

    while(k--){
        ll m = ++N[n/2];
        int lo = n/2 + 1;
        int hi = n-1;

        int pos = n/2;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(N[mid] < m){
                pos = mid;
                lo = mid + 1;
            }else{
                hi = mid-1;
            }
        }

        if(pos != n/2){
            swap(N[n/2], N[pos]);
        }

        cout << endl;
    }
    
    cout << N[n/2] << endl;
}

