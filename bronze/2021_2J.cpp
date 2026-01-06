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

    int even = 0;
    int odd = 0;
    int n; 
    cin >> n;
    rep(i,0,n){
        int temp; cin >> temp;
        if(temp%2==0){
            even++;
        }else{
            odd++;
        }
    }

    while(odd > even){
        odd -= 2;
        even++;
    }
    int maxg;
    if(even > odd + 1){
        maxg=2*odd + 1;
    }else{
        maxg=even+odd;
    }
    cout << maxg<< endl;
}

