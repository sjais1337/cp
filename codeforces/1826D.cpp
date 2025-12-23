#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> C(n);

    for(int i = 0; i < n; i++){
        cin >> B[i];
        int a = B[i] + i;
        int c = B[i] - i;
        A[i] = a;
        C[i] = c;
    }

    ll tot = -2e18;
    ll max_a = -2e18;

    vector<ll> C_max(n);
    C_max[n-1] = -2e18;

    for(int i = n-2; i >= 0; i--){
        C_max[i] = max(C[i+1], C_max[i+1]);
    }

    for(int i = 1; i < n-1; i++){
        max_a = max(max_a, A[i-1]);        
        ll sum = B[i] + max_a + C_max[i];
        tot = max(sum, tot);
    }
    
    cout << tot << endl;  
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

