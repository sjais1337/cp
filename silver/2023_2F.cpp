#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int G, N;
    cin >> G >> N;

    vector<tuple<ll,ll,ll>> SG(G);
    vector<tuple<ll,ll,ll>> COWS(N);

    for(int i = 0; i < G; i++){
        ll x, y, t;
        cin >> x >> y >> t;
        SG[i] = make_tuple(t, x, y);
    }
    
    for(int i = 0; i < N; i++){
        ll x, y, t;
        cin >> x >> y >> t;
        COWS[i] = make_tuple(t, x, y);
    }

    sort(SG.begin(), SG.end());
    
    int good_cows = 0;

    for(int i = 0; i < N; i++){
        ll c_x = get<1>(COWS[i]), c_y = get<2>(COWS[i]);
        ll c_t = get<0>(COWS[i]);

        auto lower = (lower_bound(SG.begin(), SG.end(), COWS[i]));

        bool works = false;

        if(lower != SG.end()){
            auto [u_t, u_x, u_y] = *(lower_bound(SG.begin(), SG.end(), COWS[i]));

            if((u_x - c_x)*(u_x - c_x) + (u_y - c_y)*(u_y - c_y) > (u_t - c_t)*(u_t - c_t)){
                works = true;
            }
        }

        if(lower != SG.begin()){
            auto [u_t, u_x, u_y] = *prev(lower);
            if((u_x - c_x)*(u_x - c_x) + (u_y - c_y)*(u_y - c_y) > (u_t - c_t)*(u_t - c_t)){
                works = true;
            }
        }

        if(works){
            good_cows++;
        }
    }

    cout << good_cows << endl;
}


