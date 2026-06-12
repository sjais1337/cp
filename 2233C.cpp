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
        int n, k; cin >> n >> k;
        string s;
        cin >> s;

        int closes = 0;
        int rem = 0;
        int opens = 0;

        int m = 0, split = 0, before = 0;
        rep(i,0,n){
            if(s[i]=='('){
                rem--;
                opens++;
            }else{
                closes++;
                rem++;
            }

            if(rem > m){
                m = rem;
                split = i+1;
                before = opens;
            }
        }

        int matched = closes - m;
        int remove = min(k, matched);
        int del_o = min(remove, before);
        int del_c = remove - del_o;

        string ans(n, '0');
        rep(i,0,split){
            if(del_o == 0) break;
            if(s[i] == '('){
                ans[i] = '1';
                del_o--;
            }
        }
        rep(i,split,n){
            if(del_c == 0) break;
            if(s[i] == ')'){
                ans[i] = '1';
                del_c--;
            }
        }

        cout << ans << endl;
    }
}

