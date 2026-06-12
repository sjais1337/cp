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

bool completed(ll n, ll x, ll y, ll z, ll t){
    ll op1 = (x+y)*t;
    ll op2 = x*t;
    if(t > z){
        op2 += 10LL*(y)*(t-z);
    }
    return max(op1, op2) >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        ll n, x, y, z; 
        cin >> n >> x >> y >> z;

        // written at time t
        // if(t >= z) => 10*y*(t-z) + x*t
        // if(t < z) => x*t

        ll left = 0, right = 1e6;

        while(left < right){
            ll mid = left + (right - left)/2;
            if(completed(n, x, y, z, mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        cout << left << endl;
    }
}

