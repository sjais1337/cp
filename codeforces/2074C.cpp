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
        int x;
        cin >> x; 

        // The triangle will be degenerate if all three hold.
        // Out of 3, one holds trivially


        // There exist active bit in same position.
        //  - Not power of two. Every other number can have a active 
        //    bit in same position for number smaller.

        // There exist active bit in y, inactive in x
        //  - Cannot be of the form 111111


        int msb = 0; 
        int temp = x;
        int found_0 = false; int p = 0;
        int found_1 = false; int q = 0;
        for(int t = 0; temp >= 1; t++){
            int dig = temp & 1;
            if(dig == 0 && !found_0) {
                found_0 = true;
                p = t;
            }
            if(dig == 1 && !found_1) {
                found_1 = true;
                q = t;
            }
            msb = t;
            temp >>= 1;
        }

        if(1<<msb == x || ((1 << (msb+1)) -1) == x){
            cout << -1 << endl; 
            continue;
        }

        cout << ((1LL << p) + (1LL << q)) << endl;
    }
}