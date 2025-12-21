#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n, b;
  cin >> n;

  vector<tuple<int, int>> coords;

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;

    coords.push_back(make_tuple(x, y));
  }

  int g_min = n;

  for (auto c : coords) {
    int a = get<0>(c) + 1;

    for (auto l : coords) {
      int b = get<1>(l) + 1;

      int one = 0, two = 0, three = 0, four = 0;

      for (auto k : coords) {
        if ((get<0>(k) <= a && (get<1>(k) <= b))) {
          one++;
        } else if ((get<0>(k) >= a) && (get<1>(k) <= b)) {
          two++;
        } else if ((get<0>(k) <= a) && (get<1>(k) >= b)) {
          three++;
        } else if ((get<0>(k) >= a) && (get<1>(k) >= b)) {
          four++;
        }
      }

      int l_min = max({one, two, three, four});
      if (g_min > l_min) {
        g_min = l_min;
      }
    }
  }

  cout << g_min << endl;
}
