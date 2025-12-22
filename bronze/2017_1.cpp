#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> log;

  for(int i = 0; i < n; i++){
    string cow;
    int prod;
    cin >> cow;
    cin >> prod;
    if(log[cow]){
      log[cow] = log[cow] + prod;
    }else{
      log[cow] = prod;
    }
  }

  vector<pair<string, int>> v(log.begin(), log.end());
  sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
  });

  int min = v[0].second;
  int pos = 0; 
  string cow;

  for(int i = 0; i < v.size(); i++){
    if(v[i].second == min && pos == 1){
      cout << "Tie" << endl;
      return 0;
    }
    if(pos == 1){
      cow = v[i-1].first;
      break;
    }
    if(v[i].second != min){
      pos++;
      min = v[i].second;
    }    
  }

  if(pos != 0){
    cout << cow << endl;
  }else{
    cout << "Tie" << endl;
  }
}
