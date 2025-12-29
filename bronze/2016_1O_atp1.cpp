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
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vec<int> sizes(n);
    for(int i =0;i<n;i++){
        cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());
    
    int ma = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(sizes[j] - k > sizes[i]){
                ma = max(j-i,ma);
                break;
            } 
            ma = max(j-i+1,ma);
        }
    }

    cout << ma << endl;
}
