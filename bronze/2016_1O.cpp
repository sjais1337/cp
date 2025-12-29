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
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi si(n);
    for(int i = 0; i < n; i++){
        cin >> si[i];
    }

    sort(si.begin(), si.end());
    int start = 0; 
    int ma = 0;
    for(int end = 0; end < n; end++){
        while(start < n && si[start] - si[end] <= k){
            start++;
        }

        ma = max(start - end, ma);
    }

    cout << ma << endl;
}
