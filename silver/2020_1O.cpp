#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int n, int m, ll D,vector<pair<ll,ll>>& I){
    ll prev = I[0].first;
    int present = 0;
    for(int i = 1; i < n; i++){
        while(present < m && (I[present].second - prev) < D){
            present++;
        }

        if(present == m) return false;

        prev = max(prev + D, I[present].first); 
    }

    return true;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> n >> m;

    vector<pair<ll, ll>> I(m);
    for(int i = 0; i < m; i++){
        cin >> I[i].first >> I[i].second;
    }

    sort(I.begin(), I.end());

    ll low = 0, high = (*(prev(I.end()))).second - (*I.begin()).first;

    while(low < high){
        ll mid = low + (high - low)/2;
        if(check(n, m, mid, I)){
            low = mid+1;
        }else{
            high = mid;
        }
    }

    cout << low << endl;
}
