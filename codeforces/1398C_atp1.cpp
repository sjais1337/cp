#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string temp;
        cin >> temp;
        vector<int> digs(n+1, 0);
        vector<int> pf(n+1,0);
        vector<int> l(n+1,0);
        int good = 0;
        for(int i = 1; i <= n; i++){
            digs[i] = temp[i-1] - '0';
            pf[i] = digs[i] + pf[i-1];
            l[i] = pf[i] - i;
        }

        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                int length = j - i + 1;
                int sum = pf[j] - pf[i-1];
                
                if(length == sum) good++;
            }
        }

        cout << good << endl;
    }

    return 0;
}

