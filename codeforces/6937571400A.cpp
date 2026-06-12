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
    vi H1(n);
    vi H2(n);
    rep(i,0,n) cin >> H1[i];
    rep(i,0,n) cin >> H2[i];

    vi ans(n, 0);

    rep(start,0,n){
        int row = 0;
        ans[start] = max(H1[start], H2[start]);
        if(ans[start] == H1[start]){
            row = 2;
        }else{
            row = 1;
        }
        int curr = start+1;
        while(curr < n && curr != n-2){
            if(row == 1){
                if(H1[curr] + H2[curr+1] < H1[curr+1]){
                    ans[start] += H1[curr+1];
                    curr += 2; 
                }else{
                    ans[start] += H1[curr];
                    curr += 1;
                }

                row = 2;
            }else if(row == 2){
                if(H2[curr] + H1[curr+1] < H2[curr+1]){
                    ans[start] += H2[curr+1];
                    curr += 2;
                }else{
                    ans[start] += H2[curr];
                    curr += 1;
                }

                row = 1;
            }
        }
        if(curr < n){
            if(row == 1){
                ans[start] += H1[curr];
            }else{
                ans[start] += H2[curr];
            }
        }
    }
    
    cout << *max_element(all(ans)) << endl;

}

