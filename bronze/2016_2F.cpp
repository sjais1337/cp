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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vi rs(n);
    for(int i =0;i<n;i++){cin>>rs[i];};
    int m = INT_MAX;
    for(int i=0;i<n;i++){
        int tot = 0;
        for(int j=0;j<n;j++){
            tot += ((n+j-i)%n)*rs[j];
        }
        m = min(tot, m);
    }
    cout << m;
}
