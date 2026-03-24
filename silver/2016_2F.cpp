#include <bits/stdc++.h>
#include <tuple>
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n;
  cin >> n;

  vec<pll> coords;

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;

    coords.push_back({x, y});
  }

  sort(coords.begin(), coords.end(), [](pll a, pll b){ return a.first < b.first; });
  rep(i,0,n){
    coords[i].first = i;
  }
  sort(coords.begin(), coords.end(), [](pll a, pll b){ return a.second < b.second; });
  rep(i,0,n){
    coords[i].second = i;
  }

  vec<vi> pos(n, vi(n,0));

  rep(i,0,n){
    pos[coords[i].first][coords[i].second] = 1;
  }

  vec<vi> ps(n+1, vi(n+1, 0));

  rep(i,1,n+1){
    rep(j,1,n+1){
      ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + pos[i-1][j-1];
    }
  }

  int m = INT_MAX;

  rep(i,1,n+1){
    rep(j,1,n+1){
      // chose the position i, j then the four parts would be given as
      // i,j - 0,0 | n, n - i,j | n,j - i,j | i,n - i,j
      m = min(m, max({
        ps[i][j] - ps[0][0], 
        ps[n][n] + ps[i][j] - ps[n][j] - ps[i][n], 
        ps[n][j] - ps[i][j], 
        ps[i][n] - ps[i][j]
      }));
    }
  }

  cout << m << endl;
}