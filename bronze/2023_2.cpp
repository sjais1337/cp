#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> stall_cooling_req(101);

    for(int i = 0; i < n; i++){
        int s, e, t;
        cin >> s >> e >> t;
        fill(stall_cooling_req.begin() + s, stall_cooling_req.begin() + e + 1, t);
    }

    vector<int> a_start(m);
    vector<int> a_end(m);
    vector<int> a_temp(m);
    vector<int> a_money(m);

    for(int i = 0; i < m; i++){
        cin >> a_start[i] >> a_end[i] >> a_temp[i] >> a_money[i];
    }

    // There are 10 ACs, thus 2^10 possibilites of turning stuff on/off. 
    // For each of them, calculate the cooling achieved and subtract with
    // the c_temp vec, check that none of them are negative. And if any n
    // egative, then skip. Else, calculate the money, if lesser than min
    // change min to present money. 

    
    int min_req = INT_MAX;

    for(int i = 0; i < (1<<m); i++){
        int money_req = 0;
        vector<int> cooling_achieved(101);

        for(int b = 0; b < m; b++){
            if((1<<b)&i){
                money_req += a_money[b];
                
                for(int j = a_start[b]; j <= a_end[b]; j++){
                    cooling_achieved[j] += a_temp[b];
                }
            }
        }

        int works = true;
        int s, e, t;
        for(int k = 1; k < 101; k++){
            if(cooling_achieved[k] - stall_cooling_req[k] < 0){
                works = false;
            }
        }

        if(works == false){
            continue;
        }

        if(min_req > money_req){
            min_req = money_req;
        }
    }

    cout << min_req << endl;

}