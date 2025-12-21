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

  int count = m;

  for (int i = 0; i < m; i++) {
    vector<char> init;
    int lol = 0;
    for (int j = 0; j < n; j++) {
      char el = matrix[j][i];

      if (find(init.begin(), init.end(), el) == init.end()) {
        init.push_back(el);
      }
    }

    for (int j = n; j < 2 * n; j++) {
      char el = matrix[j][i];

      if (find(init.begin(), init.end(), el) != init.end()) {
        lol = 1;
      }
    }

    count -= lol;
  }

  cout << count << endl;
}
