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
    
    int t; 
    cin >> t;
    
    while(t--){
        ll n, f, a, b; 
        cin >> n >> f >> a >> b;
        
        vll M(n+1);
        rep(i,1,n+1){
            cin >> M[i];
        }

        ll req = 0;
        rep(i,0,n){
            req += min((M[i+1]-M[i])*a, b);
        }

        if(req < f){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}


