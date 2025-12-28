#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int n, ll k, vector<ll>& A, ll diff){
    for(int i = 0; i < n; i++){
        if(A[i] > A[n-1] - diff){
            k -= A[0] + diff - A[i];        
        }
    }

    return k >= 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll A_max = *prev(A.end());

    ll low = 0, high = 1e9;

    while(low < high){
        ll mid = low + (high - low)/2;
        if(check(n, k, A, mid)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    cout << low << endl;
}

