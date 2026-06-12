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
    vi X(n);
    rep(i,1,n+1) X[i-1] = i;

    int m = 0;
    rep(i,0,n) { 
        m += X[i];
    }

    vec<int> tries(m+1,0);
    tries[0]=true;

    rep(i,0,n){
        rrep(j,m,0){
            if(j - X[i] >= 0 && tries[j - X[i]]){
                tries[j]++;
            }
        }
    }

    rep(i,0,m+1){
        cout << i << ": " << tries[i] << endl;
    }
}

