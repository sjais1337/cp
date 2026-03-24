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

    while (t--)
    {
        int n, q; 
        cin >> n >> q; 
        
        vi a(n);
        vi b(n);

        rep(i,0,n){
            cin >> a[i];
        }
        rep(i,0,n){
            cin >> b[i];
        }

        rrep(i,n-1,0){
            if(i==n-1){
                a[i] = max(a[i],b[i]);
            }else{
                a[i] = max({a[i], b[i], a[i+1]});
            }
        }

        vi ps(n+1,0);

        rep(i,1,n+1){
            ps[i] = ps[i-1]+a[i-1];
        }
 
        while(q--){
            int l,r; cin >> l >> r;
            int sum = ps[r] - ps[l-1];
            cout << sum << " ";
        }

        cout << endl;
    }
    
}

