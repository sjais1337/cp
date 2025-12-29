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
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi xs(n);
    vi ys(n);
    for(int i=0;i<n;i++){
        cin >> xs[i];
        cin >> ys[i];
    }

    int m = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                if(
                    (xs[i]==xs[j] || xs[j]==xs[k] || xs[k]==xs[i]) &&
                    (ys[i]==ys[j] || ys[j]==ys[k] || ys[k]==ys[i])
                ){
                    int area = abs(xs[i]*(ys[j] - ys[k]) + xs[j]*(ys[k]-ys[i]) + xs[k]*(ys[i]-ys[j]));
                    m = max(area,m);
                }
            }
        }
    }

    cout << m;
}
