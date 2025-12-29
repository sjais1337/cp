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
    vi pi(n+1);
    vi ps(n+1,0);
    for(int i = 1; i <= n;i++){
        cin >> pi[i];
        ps[i] = ps[i-1] + pi[i];
    }

    int count = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i; j <= n; j++){
            float avg = ((float) (ps[j]-ps[i-1]))/((float)(j-i+1));

            for(int z = i; z <= j; z++){
                if((float)pi[z] == avg){
                    count++;
                    break;
                }
            }                
        }
    }

    cout << count;
}

