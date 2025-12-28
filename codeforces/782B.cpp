#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
bool check(int n, vector<ll> SP, vector<ll> X, ld time){
    ld lm = LLONG_MIN, rm = LLONG_MAX;
    for(int i = 0; i < n; i++){
        lm = max(lm, X[i] - time*SP[i]);
        rm = min(rm, X[i] + time*SP[i]);
    }

    return lm <= rm;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ll> X(n);
    vector<ll> SP(n);

    for(int i = 0; i < n; i++) cin >> X[i];
    for(int i = 0; i < n; i++) cin >> SP[i];

    ld low = 0, high = 1e9;
    
    for(int i = 0; i < 100; i++){
        ld mid = low + (high - low)/2;
        if(check(n, SP, X, mid)){
            high = mid;
        }else{
            low = mid;
        }
    }

    cout << fixed << setprecision(10) << high << endl;
}

