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

    int n, k;
    cin >> n >> k;

    vi C(n);
    rep(i,0,n) cin >> C[i];

    vec<vec<bool>> dp(k+1, vec<bool>(k+1, 0));
    dp[0][0] = 1;

    rep(i,0,n){
        vec<vec<bool>> new_dp(dp);
        rrep(j,k,C[i]){
            rrep(r,k,0){
                new_dp[j][r] = dp[j-C[i]][r] | new_dp[j][r];
                new_dp[r][j] = dp[r][j-C[i]] | new_dp[r][j];
            }
        }

        dp = new_dp;
    }

    set<int> ans;

    rep(i, 0, k+1){
        int j = k - i;
        if(dp[i][j]) {
            ans.insert(i);
        }
    }

    cout << ans.size() << endl;

    for(int c: ans){
        cout << c << " ";
    }

}

