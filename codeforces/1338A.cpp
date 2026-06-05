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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n; 
        cin >> n; 

        vi arr(n);

        rep(i,0,n) {
            cin >> arr[i];
        }
        
        vi n_arr(n);
        int fin = 0;

        n_arr[0] = arr[0];
        rep(i,1,n){
            n_arr[i] =  max(n_arr[i-1], arr[i]);
        }

        rep(i,0,n){
            fin |= n_arr[i] - arr[i];
        }

        int T = 0;
        while(fin != 0){
            T++;
            fin = fin >> 1;
        }

        cout << T << endl;
    }
    
}

