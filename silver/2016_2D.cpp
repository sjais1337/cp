#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> counts;

  while(n--){
    string city, state;
    cin >> city >> state;

    city = city.substr(0, 2);
    string ss = city + state;

    counts[ss]++;
  }

  int tot_pairs = 0;

  for(auto &x: counts){
    string h = x.first;
    string p1 = h.substr(0,2);
    string p2 = h.substr(2,2);
    if(p1 != p2){
      string ss = p2 + p1;
      tot_pairs += counts[h]*counts[ss];
    }
 }

  cout << tot_pairs/2 << endl;
}
