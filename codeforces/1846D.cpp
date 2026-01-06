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
    cout.setf(ios::fixed);
    cout << setprecision(10);

    while(t--){
        int n;
        ld d,h;
        cin >> n >> d >> h;
        ld sum = 0;
        ld prev = 0;
        vec<ld> ys(n);
        for(int i = 0; i< n;i++){
            cin >> ys[i];
        }
        sort(ys.begin(), ys.end());
        for(int i = 0; i<n;i++){
            ld yi = ys[i];
            ld diff = yi - prev;

            sum += 0.5*d*h;

            prev = prev + yi + h;
            if(i > 0){
                ld dl = ys[i]-ys[i-1];
                if(dl < h){
                   ld oh = h-dl;
                   sum -= 0.5*d*oh*oh/h;
                }
            }
        }
            
        cout << sum << endl;
    }
}

