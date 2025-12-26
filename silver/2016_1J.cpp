#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int n, int k, ll R, vector<ll>& P){
    int used = 1;
    int start = 0;
    // cout << "Radius: " << R << endl;
    for(int i = 0; i < n; i++){
        if((P[i] - P[start]) > 2*R){
            // cout << "Curernt: " << i << ',' << P[i] << " , Start: " << start << ',' << P[start] << endl;
            start = i;
            used++;
        }
    }
    // cout << "-----------------" << endl;
    return used <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> P(n);
    for(int i = 0; i < n; i++){
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    ll low = 0, high = *(prev(P.end())) - *P.begin();

    while(low < high){
        ll mid = low + (high - low)/2;
        if(check(n, k, mid, P)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    cout << low << endl;
}
