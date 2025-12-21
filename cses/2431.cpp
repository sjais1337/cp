#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int q;
  cin >> q;

  while (q--) {
    ll k;
    cin >> k;

    ll dig = 1;
    ll cnt = 9;

    while (k > dig * cnt) {
      k -= dig * cnt;
      dig++;
      cnt *= 10;
    }

    ll index = (k - 1) / dig;
    ll num = (ll)pow(10, dig - 1) + index;

    string s = to_string(num);
    cout << s[(k - 1) % dig] << "\n";
  }
}
