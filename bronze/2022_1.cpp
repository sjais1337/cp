#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string initial;

  cin >> n;
  cin >> initial;

  int count = 0;

  while (true) {
    int odd = 0, even = 0;
    int gain = 0;
    for (int i = 0; i < initial.length(); i += 2) {
      if (initial[i] == 'G') {
        odd++;
      }

      if (i + 1 < n && initial[i + 1] == 'G') {
        even++;
      }

      int curr_gain = odd - even;

      if (curr_gain >= gain) {
        gain = curr_gain;
      } else {
        reverse(initial.begin(), initial.begin() + i + 2);
        count++;
        break;
      }
    }
  }

  cout << count;
}
