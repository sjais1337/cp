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
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
    vi fi(n,0);
    rep(i,0,n){
        char a;cin>>a;
        fi[i] = a == '1' ? 1 : 0;
    }
    vec<vi> shakes;
    rep(i,0,t){
        cin >> shakes[i][0] >> shakes[i][1] >> shakes[i][2];
    }
    sort(shakes.begin(), shakes.end(),[](vi a, vi b){
        return a[0] < b[0];
    });
    rep(i,0,n){
        // go from k 0 to t 
        // set the candidate patient 0 to 1
        // if infected[i] == 1 (either of the two) and shakes left, then set the shaked to 1 too 
        // if works, set min k, then if bigger set max 

    }
}
