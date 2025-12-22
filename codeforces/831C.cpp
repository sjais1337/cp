#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, n;
    cin >> k >> n;
    vector<ll> A(k);

    vector<ll> pf(k);
    cin >> A[0]; 
    pf[0] = A[0];
    
    for(int i = 1; i < k; i++){
        cin >> A[i];
        pf[i] = pf[i-1] + A[i];
    }

    set<ll> ps(pf.begin(), pf.end());

    vector<ll> B(n);
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    set<ll> val;
    for(int j = 0; j < k; j++){
        ll x = B[0] - pf[j];
        int works = 1;
        for(int i = 0; i < n; i++){
            if(!ps.count(B[i] - x)){
                works = 0;
                break;
            }
        }

        if(works) val.insert(x);
    }

    cout << val.size() << endl;

    return 0;
}

