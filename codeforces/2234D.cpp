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
        int n; int k;
        cin >> n >> k;
        string first;  
        string last;
        string mid;

        cin >> first;
        cin >> last;

        int active_f = 0;
        int active_l = 0;
        int active_m = 0;

        for(int i = 0; i < n; i++){
            if(first[i] == '1') active_f++;
            if(last[i] == '1') active_l++;

            if(first[i] == last[i]){
                mid.push_back('0');
            }else{
                mid.push_back('1');
                active_m++;
            }
        }

        ll num_first, num_last, num_mid;
        if(k%2==0){
            num_first = ((1LL<<k) + 1)/3 + 1;
            num_last = ((1LL<<k) + 1)/3 + 1;
            num_mid = ((1LL<<k) + 1)/3;
        }else{
            num_first = ((1LL<<k) + 1)/3;
            num_last = ((1LL<<k) + 1)/3;
            num_mid = ((1LL<<k) + 1)/3;
        }

        ll tot = num_first*(active_f)*(n-active_f) + num_mid*(active_m)*(n-active_m) + num_last*(active_l)*(n-active_l);
        
        cout << tot << endl;
    }
}

