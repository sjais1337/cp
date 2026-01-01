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

    int n, k;
    cin >> n >> k;

    vll days(n+1,0);
    for(int i =1; i<=n;i++){
        cin >> days[i];
    }
    
    ll min = k+1;
    for(int i = 2;i<=n;i++){
        if(days[i]-days[i-1] <= k){
            min += days[i] - days[i-1];
        }else{
            min += k +1;
        }
    }

    cout << min << endl;
}

