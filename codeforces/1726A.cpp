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
        vi A(n);

        for(int i = 0; i < n; i++){
            cin >> A[i];
        }

        int initial = A[n-1] - A[0];

        // assume 0 fixed
        for(int i = 1; i < n; i++){
            initial = max(A[i] - A[0], initial);
        }

        // assume n-1 fixed
        for(int i = 0; i < n-1; i++){
            initial = max(A[n-1] - A[i], initial);
        }

        // assume neither fixed
        for(int i = 0; i < n; i++){
            initial = max(A[(n-1+i)%n] - A[i], initial);
        }

        cout << initial << endl;
    }
}

