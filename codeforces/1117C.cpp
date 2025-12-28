#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> disp_x;
vector<ll> disp_y;



bool check(int n, pair<ll, ll> p1, pair<ll, ll> p2, ll mid){
    ll x_needed = p2.first - p1.first, y_needed = p2.second - p1.second;

    ll N = mid / n;
    int rem = (mid % n);
    ll x_disp = N*disp_x[n] + disp_x[rem];
    ll y_disp = N*disp_y[n] + disp_y[rem];

    return (abs(x_disp - x_needed) + abs(y_disp - y_needed) ) <= mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    disp_x.push_back(0);
    disp_y.push_back(0);
    
    pair<ll,ll> p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;

    int n;
    cin >> n;
    vector<char> W(n);

    for(int i = 0; i < n; i++){
        cin >> W[i];
    }
    
    for(int i = 1; i <= n; i++){
        char dir = W[i - 1];
        ll x_disp = disp_x[i-1], y_disp = disp_y[i-1];
        if(dir == 'U'){
            y_disp++;
        }else if(dir == 'D'){
            y_disp--;
        }else if(dir == 'L'){
            x_disp--;
        }else if(dir == 'R'){
            x_disp++;
        }
        disp_x.push_back(x_disp);
        disp_y.push_back(y_disp);
    }

    ll low = 0, high = LLONG_MAX;
    
    while(low < high){
        ll mid = low + (high - low)/2;
        if(check(n, p1, p2, mid)){
            high = mid;
        }else{
            low = mid+1;
        }
    }

    if(high == LLONG_MAX){
        cout << -1 << endl;
        return 0;
    }

    cout << low << endl;
}

