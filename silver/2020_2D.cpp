#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double 
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T> using Matrix = vector<vector<T>>;

constexpr int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pll> P(n);
    for(int i = 0; i < n; i++)  { 
        cin >> P[i].first >> P[i].second; 
    } 
    
    sort(all(P), [](pll a, pll b){ return a.second < b.second; });
    for(int i = 0; i < n; i++){ P[i].second = i+1; }

    sort(all(P), [](pll a, pll b){ return a.first < b.first; });
    for(int i = 0; i < n; i++){ P[i].first = i+1; }   

    Matrix<int> pref(n+1, vector<int>(n+1,0));

    for(int i = 0; i < n; i++){
        pref[P[i].first][P[i].second] = 1;
    }    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] += pref[i-1][j] + pref[i][j-1] -  pref[i-1][j-1];
        }
    }

    ll tot = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int y1 = min(P[i].second, P[j].second);
            int y2 = max(P[i].second, P[j].second);

            int up = pref[j+1][n] - pref[i][n] - (pref[j+1][y2-1] - pref[i][y2-1]);
            int down = pref[j+1][y1] - pref[i][y1];

            tot += (ll)(up)*(down);
        }
    }

    cout << tot + 1 << endl;
}
