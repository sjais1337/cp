#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vl vector<ll>
#define rep(var, start, end) for(int var = start; i < end; var++)
#define all(v) v.begin(), v.end()

bool check(ll W, int n, int c, int m, vl& T){
    int used = 0;
    int idx = 0;

    while(used < m && idx < n){
        int end = 0;
        while(idx+end < n && end < c && T[idx+end] - T[idx] <= W){
            end++;
        }
        used++;
        idx+=end;
    }

    return idx == n;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;

    vl T(n);
    rep(i,0,n){
        cin >> T[i];
    }
    sort(all(T));

    ll low = 0; 
    ll high = *prev(T.end());

    while(low < high){
        ll mid = low + (high - low)/2;
        if(check(mid, n, c, m, T)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    
    cout << low << endl;
}
