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
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<int> limits(100);
    int k = 0;
    for(int i = 0; i < n; i++){
        int l, s;
        cin >> l >> s;
        fill(limits.begin() + k, limits.begin() + k + l, s);
        k += l;
    }

    k = 0;
    vec<int> speeds(100);
    for(int i = 0; i < m; i++){
        int l, s;
        cin >> l >> s;
        fill(speeds.begin() + k, speeds.begin() + k + l, s);
        k += l;
    }

    int ma = 0;
    for(int i = 0; i < 100; i++){
        ma = max(speeds[i] - limits[i], ma);
    }
    cout << ma;
}
