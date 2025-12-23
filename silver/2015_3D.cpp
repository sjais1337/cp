#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<int> h(n+1, 0), g(n+1, 0), j(n+1, 0);
  for(int i = 1; i <= n; i++){
    int temp;
    cin >> temp;

    h[i] = h[i-1]; 
    g[i] = g[i-1]; 
    j[i] = j[i-1]; 
    
    if(temp == 1) h[i]++ ;
    else if(temp == 2) g[i]++;
    else if(temp == 3) j[i]++;
  }

  for(int i = 0; i < q; i++){
    int a,b;
    cin >> a >> b;
    int hc = h[b] - h[a-1];
    int gc = g[b] - g[a-1];
    int jc = j[b] - j[a-1];

    cout << hc << " " << gc << " " << jc << endl;
  }

}
