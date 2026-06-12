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
    int m = n * (n + 1)/2;
    if(m%2 != 0) {  cout << 0; return 0; }
    int target = m / 2; 

    vec<ll> tries(target+1,0);
    tries[0]= 1;

    rep(i,1,n){
        rrep(j,target,i){
            tries[j] = (tries[j] + tries[j-i]) % MOD;
        }
    }

    cout << tries[target];
    return 0;
}

