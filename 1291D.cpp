#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(string& t){
 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string t;
    int q;
    cin >> t;

    while(q--){
        int l, r;
        cin >> l >> r;
        string sub = t.substr(l-1, r-l+1);
        
        solve(sub);
    }
}

