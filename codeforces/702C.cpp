#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> C(n);
    vector<ll> T(m);

    for(int i = 0; i < n; i++){
        cin >> C[i];
    }

    for(int i = 0; i < m; i++){
        cin >> T[i];
    }

    ll pos = 0;
    ll r = 0;

    for(int i = 0; i < n; i++){
        while (pos + 1 < m && (abs(C[i] - T[pos]) >= abs(C[i] - T[pos+1]))){
            pos++;
        }
        
        r = max(abs(T[pos] - C[i]), r);
    }

    cout << r;
}

