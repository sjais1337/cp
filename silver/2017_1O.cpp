#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);

  ll N;
  cin >> N;

  vector<pair<ll, ll>> cows;


  for(ll i = 0; i < N; i++){
    ll x, y; cin >> x >> y;
    cows.push_back({y, x});
  }

  sort(cows.begin(), cows.end());

  ll start = 0, end = N-1;

  ll max_time = 0;

  while(start <= end){
    ll cows_l = cows[start].second;
    ll cows_m = cows[end].second;

    ll to_subtract = min(cows_l, cows_m);
    
    ll time = cows[start].first + cows[end].first;

    max_time = max(time, max_time);

    cows[start].second -= to_subtract;
    cows[end].second -= to_subtract;

    if(start < end && cows[start].second == 0){
      start++;
    }
    
    if(end >= 0 && cows[end].second == 0){
      end--;
    }
  }

  cout << max_time;
  return 0;
}
