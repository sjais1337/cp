#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f_min(vector<ll>& B, ll a){
    auto it = lower_bound(B.begin(), B.end(), a);
    ll min_ = LLONG_MAX;
    if (it != B.end()) min_ = min(min_, abs(*it - a));
    if (it != B.begin()) min_ = min(min_, abs(*prev(it) - a));
    return min_;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> A(n), B(m);

    ll A_sum = 0;
    ll B_sum = 0;
    vector<ll> AB_sum;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        A_sum += (i%2 == 0) ? A[i] : -A[i];
    }

    for(int i = 0; i < m; i++){
        cin >> B[i];
        if(i < n) B_sum += (i%2 == 0) ? B[i] : -B[i];
    }

    AB_sum.push_back(B_sum);

    for(int j = 1; j <= m - n; j++){
        B_sum -= B[j-1];
        B_sum = -B_sum;
        B_sum += (n%2 == 0) ? -B[j+n-1] : B[j+n-1];
        AB_sum.push_back(B_sum);
    }

    sort(AB_sum.begin(), AB_sum.end());

    cout << f_min(AB_sum, A_sum) << endl;

    while(q--){
        int l, r; 
        ll x;
        cin >> l >> r >> x;

        if(l%2 == r%2){
            A_sum += (l%2) == 0 ? -x : x;
        }else{
            A_sum = A_sum;            
        }

        cout << f_min(AB_sum, A_sum) << endl;
    }
}

