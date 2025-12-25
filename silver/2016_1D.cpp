#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<ll> P(n);
  for(int i = 0; i < n; i++){
    cin >> P[i];
  }

  sort(P.begin(), P.end());

  while(q--){
    ll s, e;
    cin >> s >> e;

    auto start = lower_bound(P.begin(), P.end(), s);
    auto end = upper_bound(P.begin(), P.end(), e);

    int len = distance(start, end);

    cout << len << endl;
  }
}
