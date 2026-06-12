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
    
    int n; 
    cin >> n;

    if(n == 1) {
        cout << 1; 
        return 0;
    }

    vi place(n);
    vi height(n);

    rep(i,0,n){
        cin >> place[i] >> height[i];
    }

    vec<vi> ans(n, vi(3, INT_MIN));
    // 1 -> left, 2 -> right, 3 -> standing
    ans[0][0] = 1;
    ans[0][2] = 0;
    if(place[1] - place[0] > height[0]){
        ans[0][1] = 1;
    }

    rep(i,2,n){
        int prev = max(ans[i-1][0], ans[i-1][2]);

        if(place[i] - place[i-1] > height[i]){
            prev = max(prev, ans[i-1][1]);
        }
        ans[i][2] = prev;

        if(place[i] - place[i-1] > height[i])
    }

}

