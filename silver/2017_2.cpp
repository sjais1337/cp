#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long;

struct tuple_hash {
  size_t operator()(const tuple<char, char, char> &t) const {
    auto [a, b, c] = t;
    return (a * 31 + b) * 31 + c; // simple rolling hash
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;

  cin >> n >> m;

  vector<vector<char>> matrix(2 * n, vector<char>(m));

  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  int count = 0;

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        int lol = 1;

        unordered_set<tuple<char, char, char>, tuple_hash> spot, nospot;

        for (int l = 0; l < n; l++) {
          spot.insert(make_tuple(matrix[l][i], matrix[l][j], matrix[l][k]));
          nospot.insert(
              make_tuple(matrix[l + n][i], matrix[l + n][j], matrix[l + n][k]));
        }

        for (auto c : nospot) {
          if (spot.count(c)) {
            lol = 0;
            break;
          }
        }

        if (lol) {
          count++;
        }
      }
    }
  }

  cout << count << endl;
}
