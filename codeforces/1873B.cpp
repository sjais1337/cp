#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double 
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()

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
        vi N(n);
        for(int i = 0; i<n;i++){
            cin >> N[i];
        }
        auto ma = min_element(N.begin(), N.end());
        *ma = *ma + 1;
        int product = 1;
        for(int i = 0; i < n; i++){
            product *= N[i];
        }
        cout << product << endl;
    }
    
    return 0;
}

