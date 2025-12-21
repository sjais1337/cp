#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int flips = 0;
  for (int i = n - 2; i < s.length(); i -= 2) {
    if (s[i] == s[i + 1]) {
      continue;
    }

    bool isGH = ((s[i] == 'G') && (s[i + 1] == 'H'));

    if ((isGH && (flips % 2 == 0)) || (!isGH && (flips % 2 == 1))) {
      flips++;
    }
  }

  cout << flips;
}
