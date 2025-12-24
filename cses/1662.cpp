#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ll> remainders(n, 0);
    ll c = 0;
    remainders[0] = 1;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        c += temp;        

        ll idx = ((c % n) + n) % n;
        remainders[idx]++;
    }

    ll tot = 0;

    for(ll i = 0; i < n; i++){
        ll val = remainders[i];

        if(val > 0){
            tot += val*(val - 1)/2;
        }
    }

    cout << tot << endl;
}

