#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    cin >> n;
    vector<char> seq(n);

    for(int i = 0; i < n; i ++){
        cin >> seq[i];
    }

    for(int i = 1; i <= n; i++){
        set<vector<char>> con;
        int l = 0;

        for(int j = 0; j <= n - i;j++){
            vector<char> sub(seq.begin() + j, seq.begin() + j + i);
            l++;
            con.insert(sub);
        }

        if(l == con.size()){
            cout << i << endl;
            return 0;
        }
    }
}

