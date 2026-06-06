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
        int n; 
        cin >> n;
        
        vi nums(n);
        rep(i,0,n) {cin >> nums[i];}
        string s; cin >> s;

        int num = 0;
        int k = s.length();
        for(int i = 0; i < k; i++){
            num += (s[k - i - 1]-'0') << i;
        }

        int q; 
        cin >> q;

        while(q--){
            int type; cin >> type;

            if(type == 1){
                int temp = 0;
                int l, r; cin >> l >> r;

                for(int i = l; i <= r; i++){
                    temp += 1 << (i-1);
                }

                num ^= temp;
            }else if(type == 2){
                int g; cin >> g; 
                int result = 0;

                for(int i = 0; i < n; i++){
                    if((num >> i) & 1) result ^= nums[i];
                }
                cout << result << " ";
            }
        }

        cout << endl;
    }
}

