
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> idx = {{"Bessie", 0}, {"Elsie", 1}, {"Mildred", 2}};
  vector<tuple<int, int, int>> logs; // (day, cowIndex, change)

  for (int i = 0; i < n; i++) {
    int day, change;
    string cow;
    cin >> day >> cow >> change;
    logs.push_back({day, idx[cow], change});
  }

  sort(logs.begin(), logs.end()); // sort by day

  vector<int> milk(3, 7);       // all start at 7
  set<int> leaders = {0, 1, 2}; // all tied at start
  int changes = 0;

  for (auto [day, cow, change] : logs) {
    milk[cow] += change;

    // find new leaders
    int maxMilk = max({milk[0], milk[1], milk[2]});
    set<int> newLeaders;
    for (int i = 0; i < 3; i++) {
      if (milk[i] == maxMilk)
        newLeaders.insert(i);
    }

    // check if leaders changed
    if (newLeaders != leaders) {
      changes++;
      leaders = newLeaders;
    }
  }

  cout << changes << "\n";
  return 0;
}
