#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll mid, int n, int k, const vector<ll>& N){
    ll cost = 0;
    for(int i = n/2; i < n; i++){
        if(mid > N[i]){
            cost += (mid - N[i]);
        }
    }

    if(cost > k) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll k;
    
    cin >> n >> k;

    vector<ll> N(n);

    for(int i = 0; i < n; i++){
        cin >> N[i]; 
    }

    sort(N.begin(), N.end());

    ll hi = N[n-1] + k;
    ll lo = N[n/2];

    ll max = lo;
    
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(check(mid, n, k, N)){
            max = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    } 

    cout << max << endl;

}

