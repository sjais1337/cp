#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double 
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T> using vec = vector<T>;
template <typename T> using Matrix = vec<vec<T>>;

constexpr int MOD = 1e9 + 7;

void solve(){
         int n; 
        cin >> n;

        vi shelf(n);
        map<int, vec<int>> nums;
        rep(i,0,n) {
            int temp; cin >> temp;
            nums[temp].push_back(i);
        }

        map<int, int> calc;

        for(const auto& [num, arr]: nums){
            int inconsistencies = 0;
            rep(i,1,arr.size()){
                if(arr[i] != (arr[i-1]+1)) inconsistencies++;
            }

            if(inconsistencies == 1){
                calc[num] = inconsistencies;
            }

            if(inconsistencies > 1) {
                cout << "NO" << endl;
                return;
            }
        }

        if(calc.size() > 2){
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
        return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
    
}

