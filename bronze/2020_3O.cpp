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
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
    vi fi(n,0);
    rep(i,0,n){
        char a;cin>>a;
        fi[i] = a == '1' ? 1 : 0;
    }
    vec<vi> shakes(t, vi(3));
    rep(i,0,t){
        cin >> shakes[i][0] >> shakes[i][1] >> shakes[i][2];
        shakes[i][1] -= 1; 
        shakes[i][2] -= 1; 
    }
    sort(shakes.begin(), shakes.end(),[](vi a, vi b){
        return a[0] < b[0];
    });
    vi candidates(n,0);
    int smallest_k = INT_MAX;
    int largest_k = INT_MIN;
    rep(i,0,n){
        if(!fi[i]) continue; 
        rep(k,0,t+2){
            vi infa(n,0);
            vi infected(n,0);
            infected[i] = k;
            infa[i] = 1;

            rep(l, 0, shakes.size()){
                int snap = infected[shakes[l][2]];
                if(infected[shakes[l][1]] > 0){
                    if(!infa[shakes[l][2]]){
                        infa[shakes[l][2]] = 1;
                        infected[shakes[l][2]] = k;
                    }
                    infected[shakes[l][1]]--;
                }

                if(snap > 0){
                    if(!infa[shakes[l][1]]){
                        infa[shakes[l][1]] = 1;
                        infected[shakes[l][1]] = k;
                    }
                    infected[shakes[l][2]]--;
                }
            }

            int works = 1;
            rep(j,0,n){
                if(infa[j] != fi[j]) works = 0;
            }
            candidates[i] = max(candidates[i], works);
            if(works){
                smallest_k = min(smallest_k, k);
                largest_k = max(largest_k, k);
            }
        }
    }

    int max_c = 0;
    rep(i,0,n){
        max_c += candidates[i];
    }

    cout << max_c << " " << smallest_k << " ";
    if(largest_k == t+1){
        cout << "Infinity";
    }else{
        cout << largest_k;
    }
}
