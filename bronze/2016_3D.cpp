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
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 0; i < m; i++){
        string s = "";
        for(int i = 0; i < n; i++){
            char c;
            cin >> c;
            for(int i = 0; i < k; i++){
                s += c;
            }
        }
        for(int i = 0; i < k; i++){
            cout << s << endl;
        }
    }
    return 0;
}
