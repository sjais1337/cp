#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    map<ll, int> sums;
    sums[0] = 1;
    ll c = 0;
        
    ll count = 0;

    for(int i = 0; i < n; i++){
        int temp; 
        cin >> temp;

        c += temp;

        count += sums[c-x];

        sums[c]++;
    }

    cout << count << endl;
}

