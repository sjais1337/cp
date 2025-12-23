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

        map<int,ll> freqs;
        freqs[0] = 1;
        int curr_pf = 0;

        for(ll i = 1; i <= n; i++){
            int dig = temp[i-1] - '0';
            curr_pf += dig;

            int val = curr_pf - i;

            freqs[val]++; 
        }

        ll good = 0;        

        for(auto &c : freqs){
            ll sec = c.second;
            if(sec != 0){
                good += sec*(sec-1)/2;
            }
        }

        cout << good << endl;

    }

    return 0;
}

