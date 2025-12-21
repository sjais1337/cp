#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> poses(n);

  for (int i = 0; i < n; i++) {
    cin >> poses[i];
  }

  // bessie can go back or front.
  // back => bessie height < others
  // front => bessie height > others

  int correct = -1;
  int b = -1;
  int trough = 0;

  for (int i = 0; i < n; i++) {
    if (poses[i] > poses[i - 1] && poses[i] > poses[i + 1]) {
      // we have found a peak, which implies bessie must have moved forward.
      b = i;

    } else if (poses[i] < poses[i - 1] && poses[i] < poses[i + 1]) {
      b = i;
      // we have found trough, which implies bessie must have moved backward.
      trough = 1;
    }
  }

  for (int j = 1; j < n; j++) {
    if (poses[j - 1] < poses[b] && poses[b] < poses[j]) {
      correct = j - 1;
    }
  }

  int counts = 0;

  if (trough) {
    set<int> s(poses.begin() + correct, poses.begin() + b);
    counts = s.size();
  } else {
    set<int> s(poses.begin() + b, poses.begin() + correct);
    counts = s.size();
  }

  cout << counts - 1;
}
