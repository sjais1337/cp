#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vi vector<int>

bool solve(int mid, ll threshold, vi& T){
    multiset<int> on_stage;
    for(int dur: T){
        if(on_stage.size() >= mid){
            int c_time = *on_stage.begin();
            on_stage.erase(on_stage.begin());
            on_stage.insert(dur + c_time);
            continue;
        }

        on_stage.insert(dur);
    }
    return (*on_stage.rbegin()) <= threshold;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi T(n);
    ll max_time = 0;
    int min_time = -1;
    for(int i = 0; i < n; i++){
        cin >> T[i];
        max_time += T[i];
        min_time = max(min_time, T[i]);
    }

    int low = 1, high = n;
    while(low < high){
        int mid = low + (high - low)/2;
        if(solve(mid, t, T)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    cout << low;
}
