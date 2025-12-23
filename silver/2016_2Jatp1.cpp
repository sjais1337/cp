#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  int largest = -1;

  ll n;
  cin >> n;
  vector<ll> ids(n+1, 0);
  vector<ll> pf(n+1, 0);

  for(ll i = 1; i <= n; i++){
    cin >> ids[i];
    pf[i] = pf[i-1] + ids[i];
  }

  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j++){
      int length = j - i + 1;
      ll sum = pf[j] - pf[i-1];
      if(length > largest && sum%((ll) 7)==0){
        largest = length;
      }
    }
  }

  cout << largest << endl;
}
