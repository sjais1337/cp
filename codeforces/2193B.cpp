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
        int n; cin >> n;
        vi arr(n);
        vi arr2(n);
        rep(i,0,n){
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        sort(arr.begin(), arr.end(), greater<>());

        rep(i,0,n){
            if(arr2[i] == arr[i]){
                continue;
            }else{
                int to_find = arr[i];
                auto it = find(arr2.begin(), arr2.end(), to_find);
                reverse(arr2.begin()+i, it+1);
                break;
            }
        } 

        rep(k,0,n){
            cout << arr2[k] << " ";
        }
        cout << endl;
    }
}

