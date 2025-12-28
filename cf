#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double 
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T> using vec = vector<T>;
template <typename T> using Matrix = vec<vec<T>>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vec<pll> it;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        it.push_back(make_pair(+1, a-1));
        it.push_back(make_pair(-1, b));
    }
    sort(it.begin(), it.end(), [](pll a, pll b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    int segments = 0;
    vll counts(n, 0);

    // A lot easier than this is to     
    for(int i = 0; i < it.size(); i++){
        segments += it[i].first;
        if(segments > 0){

            counts[segments-1] += (it[i+1].second - it[i].second);
            // if(it[i+1].first == -1 && it[i].first == -1){
            //     counts[segments-1] += (it[i+1].second - it[i].second);
            // }else if(it[i+1].first == -1 && it[i].first == 1){
            //     counts[segments-1] += (it[i+1].second - it[i].second)+1;
            // }else if(it[i+1].first == 1 && it[i].first == -1){
            //     counts[segments-1] += (it[i+1].second - it[i].second)-1;
            // }else{
            //     counts[segments-1] += (it[i+1].second - it[i].second);
            // }
        }
    }

    for(ll x: counts){
        cout << x << " ";
    }
}

