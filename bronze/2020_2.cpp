#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);

  int n;
  vector<char> target(n);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> target[i];
  }

  int count = 0;
  bool flag = false;

  for (int i = 0; i < n; i++) {
    char curr;
    cin >> curr;

    if (target[i] != curr) {
      if (flag == false) {
        count++;
      }
      flag = true;
    } else {
      flag = false;
    }
  }

  cout << count;
}
