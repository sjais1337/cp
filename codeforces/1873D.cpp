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

    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vec<int> s(n+k,0);
        int ops = 0;
        for(int i  =0; i<n;i++){
            char temp;
            cin >> temp;
            s[i] = temp == 'B' ? 1 : 0;
        }
        int pos = 0;
        while(pos < n){
            if(s[pos+k] - s[pos] == -1 || (s[pos] == 1 && s[pos+k] == 1)){
                ops++;
                fill(s.begin()+pos, s.begin()+pos+k, 0);
            }
            pos++;
        }
        cout << ops << endl;
    }
    
}

