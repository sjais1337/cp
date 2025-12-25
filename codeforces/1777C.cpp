#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> S(n);
    set<int> T;
    vector<int> P(n);

    for(int i = 0; i < n; i++){
        cin >> S[i];
    }

    map<int, int> prof;

    int c_min = INT_MAX;
    int c_max = -1;

    int c_diff = -1;
    int start = 0;

    for(int end = 0; end < n; end++){
        c_min = min(S[end], c_min);
        c_max = max(S[end], c_max);

        for(int i = 1; i <= m; i++){
            if(!S[end]%i) P[end] = i;
        }

        prof[P[end]]++;

        while(prof.size() == m){
            cout << start << " " << end << endl; 
            if(c_diff == -1){
                c_diff = c_max - c_min;
            }
            c_diff = min(c_diff, c_max - c_min);
            prof[P[start]]--;
            if(prof[P[start]] == 0) prof.erase(P[start]);
            start++;
        }
    }

    cout << c_diff << endl;
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

