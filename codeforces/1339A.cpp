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
    
    // if vertical diamond chosen, entire shape determined, hence for each there's at least one way

    // now, if vertical not chosen, and instead slant is chosen, then the problem is reduced to one for n-1
    // now for n = 1, answer is 1 
    // now for n = 2, answer is 2
    // for n = 3, 1 + 2 => 3. 
    // for n = 4, 1 + 

    int t; 
    cin >> t;

    while(t--){
        int n; 
        cin >> n; 
        cout << n << endl;
    }
}

