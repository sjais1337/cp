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
    
    int n; cin >> n;
    vi H(n);

    rep(i,0,n) cin >> H[i];

    vi cost(n);
    cost[0] = 0;
    cost[1] = abs(H[1] - H[0]);

    for(int i = 2; i < n; i++){
        cost[i] = min(cost[i-1] + abs(H[i] - H[i-1]), cost[i-2] + abs(H[i] - H[i-2]));
    }

    cout << cost[n-1];
}

