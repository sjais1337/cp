#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  ll n;
  cin >> n;

  vector<int> f_occ(7,-1);
  f_occ[0] = 0;

  ll curr_sum = 0;
  int max_len = 0;

  for(int i = 0; i < n; i++){
    ll temp;
    cin >> temp;

    curr_sum += temp;
    int remainder = (curr_sum)%7;

    if(f_occ[remainder] == -1) f_occ[remainder] = i; 

    max_len = max(max_len, i - f_occ[remainder]);
  }

  cout << max_len << endl;
}
