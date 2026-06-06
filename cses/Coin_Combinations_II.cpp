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

    
    int x; int n; cin >> n; cin >> x;
    vi T(x+1, 0);
    vi C(n);
    sort(all(C));

    rep(i,0,n) cin >> C[i];

    T[0] = 1;
    for(int c: C){
        rep(i,1,x+1){
            if(i-c >= 0){
                T[i] += T[i-c];
                T[i] = T[i] % MOD;
            }
        }
    }

    cout << T[x];
}
