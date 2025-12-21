
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> pos = {1, 2,
                     3}; // pos[i] = label of shell currently at position (i+1)
  vector<int> points(4, 0); // 1-based indexing: points[label]

  for (int i = 0; i < n; i++) {
    int a, b, g;
    cin >> a >> b >> g;

    // swap shells at positions a and b
    swap(pos[a - 1], pos[b - 1]);

    // guessed position g has label pos[g-1]
    int label = pos[g - 1];
    points[label]++;
  }

  cout << max({points[1], points[2], points[3]}) << "\n";
  return 0;
}
