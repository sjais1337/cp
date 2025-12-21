#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> counts(26);
  for (int i = 0; i < n; i++) {
    string w1, w2;
    cin >> w1 >> w2;

    vector<int> c1(26);
    vector<int> c2(26);

    for (char i : w1) {
      c1[i - 'a']++;
    }

    for (char i : w2) {
      c2[i - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      counts[i] += max(c1[i], c2[i]);
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << counts[i] << "\n";
  }

  return 0;
}
