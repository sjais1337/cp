#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int lol = 1;

    unordered_set<char> spot, nospot;

    for (int j = 0; j < n; j++) {
      spot.insert(matrix[j][i]);
      nospot.insert(matrix[n + j][i]);
    }

    for (char c : nospot) {
      if (spot.count(c)) {
        lol = 0;
      }
    }

    if (lol) {
      count++;
    }
  }

  cout << count << endl;
}
