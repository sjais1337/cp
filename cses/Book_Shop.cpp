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

    int n, x; 
    cin >> n >> x;
    vi H(n), S(n);
    
    rep(i,0,n) cin >> H[i];
    rep(i,0,n) cin >> S[i];

    vi ans(x+1,0);

    for(int i = 0; i < n; i++){
        for(int w = x; w >= H[i]; w--){
            ans[w] = max(ans[w], ans[w-H[i]] + S[i]);
        }
    }

    // solve(0);

    // def solve:
    //  cost < x:
    //      m = max(pages, m)
    //  use this book 
    //      cost += H[i] 
    //      pages += S[i]
    //      solve(i+1)
    //  not use this book
    //      cost -= H[i] 
    //      pages -= S[i]
    //      solve(i+1)



    // vi pages(x+1,0);
    // vec<vec<bool>> used(x+1, vec<bool>(n, false));

    // for(int i = 1; i <= x; i++){
    //     int c_used = -1; 

    //     for(int j = 0; j < n; j++){
    //         if(i - H[j] >= 0){
    //             if(!used[i - H[j]][j]){
    //                 int temp = pages[i];
    //                 pages[i] = max(pages[i], S[j] + pages[i-H[j]]);
    //                 if(temp != pages[i]) c_used = j;
    //             }
    //         }
    //     }

    //     if(c_used == -1) continue;

    //     used[i] = used[i-H[c_used]];
    //     used[i][c_used] = true;
    // }

    // cout << pages[x];
    
}

