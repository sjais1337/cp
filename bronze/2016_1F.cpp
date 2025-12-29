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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,m;
    cin >> x >> y >> m;

    int m_x = m/x;
    int ma = 0; 
    
    for(int i = 0; i <= m_x; i++){
        int xq = i*x;
        int yq = (m-xq)/y;

        xq += yq*y;
        ma = max(xq, ma);
    }
    cout << ma << endl;
}
