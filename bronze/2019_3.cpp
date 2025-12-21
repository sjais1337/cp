#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  sort(cows.begin(), cows.end());
  
  int n;
  cin >> n;
  vector<pair<string, string>> constraints;
  for(int i = 0; i < n; i++){
    string first;
    string second;
    string garbage;
    cin >> first >> garbage >> garbage >> garbage >> garbage >> second;
    constraints.push_back(pair(first, second));
  }

  do{
    bool works = true;
    for(int i = 0; i < n; i++){
      auto f_index = find(cows.begin(), cows.end(), constraints[i].first);
      auto s_index = find(cows.begin(), cows.end(), constraints[i].second);
      
      if(abs(distance(cows.begin(), f_index) - distance(cows.begin(), s_index)) != 1){
        works = false;
      }
    }

    if(works){
      for(int i = 0; i < cows.size(); i++){
        cout << cows[i] << endl;
      }
      break;
    }
  }while(next_permutation(cows.begin(), cows.end()));
}
