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
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi C(n);
        rep(i,0,n) cin >> C[i];

        sort(rAll(C));
        int x = C[0], y = C[1];
        bool works = true;
        rep(i,0,n-2){
            if((C[i+2] != (C[i]%C[i+1]))) {
                works = false;
            }
        }
        if(works){
            cout << x << " " << y << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}

