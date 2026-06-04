#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double 
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T> using vec = vector<T>;
template <typename T> using Matrix = vec<vec<T>>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vi a(n+1);
    map<int, int> tot_freq;

    rep(i,0,n){
        cin >> a[i];
        tot_freq[a[i]]++;
    }

    vi possible;
    for(auto c: tot_freq){
        if(c.second >= c.first){
            possible.push_back(c.first);
        }
    }

    vec<vi> pref(possible.size(), vi(n+1,0));
    rep(i,0,possible.size()){
        int val = possible[i];
        rep(j,1,n+1){
            pref[i][j] = pref[i][j-1] + (a[j-1]==val ? 1:0);
        }
    }


    rep(i,0,m){
        int l,r;
        cin >> l >> r;
        int tot=0;
        rep(j,0,possible.size()){
            if(pref[j][r]-pref[j][l-1]==possible[j]) tot++;
        }
        cout << tot << endl;
    }
}


