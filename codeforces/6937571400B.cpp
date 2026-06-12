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

vll F;

void calc(int n){
    for(int i = 2; i < n; i++) {
        ll ans = F[i-1] + F[i-2];
        ans = ans % MOD;
        F.push_back(ans);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    F.push_back(0); // 0th term
    F.push_back(1); // 1st term

    s.push_back('a');
    
    calc(1e5);

    int u_c = 0;
    int n_c = 0;
    
    ll ans = 1;

    for(char c: s){
        if(c == 'm' || c == 'w') {
            cout << 0; return 0;
        }

        if(c != 'u' && u_c){
            ans *= F[u_c+1];
            ans = ans % MOD;
            u_c = 0;
        }

        if(c != 'n' && n_c){
            ans *= F[n_c+1];
            ans = ans % MOD;
            n_c = 0;
        } 

        if(c == 'u'){
            u_c++;
        }

        if(c == 'n'){
            n_c++;
        }
    }

    cout << ans << endl;
    return 0;
}

