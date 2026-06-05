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

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vi W(n);
    rep(i, 0, n) cin >> W[i];

    vi counts((1 << n), 0);
    rep(iter, 0, m) {
        string s; 
        cin >> s;
        int x = 0;
        rep(j, 0, n) {
            if (s[j] == '1') x |= (1 << j);
        }
        counts[x]++;
    }

    vi wus((1 << n), 0);
    rep(i, 0, (1 << n)) {
        rep(j, 0, n) {
            if (i & (1 << j)) wus[i] += W[j];
        }
    }

    vec<vi> mat(1 << n, vi(101, 0));
    rep(i, 0, 1 << n) {
        rep(j, 0, 1 << n) {
            int match = (~(i ^ j)) & ((1 << n) - 1);
            int wu = wus[match];
            
            if (wu <= 100) {
                mat[i][wu] += counts[j];
            }
        }

        rep(k, 1, 101) mat[i][k] += mat[i][k - 1];
    }

    rep(iter, 0, q) {
        string s; 
        int k; 

        cin >> s >> k;
        
        int x = 0;
        rep(j, 0, n) {
            if (s[j] == '1') x |= (1 << j);
        }

        if (k > 100) k = 100;
        
        cout << mat[x][k] << "\n";
    }
    
    return 0;
}