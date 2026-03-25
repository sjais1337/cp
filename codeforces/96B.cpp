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

vll super_lucky;

void gen(ll curr, int n4, int n7){
    if(n4 + n7 > 10){
        return;
    }

    if(n4 == n7 && n4 > 0 && n7 > 0) super_lucky.push_back(curr);

    gen(curr*10 + 4, n4 + 1, n7);
    gen(curr*10 + 7, n4, n7 + 1);
}

template <typename T> using vec = vector<T>;
template <typename T> using Matrix = vec<vec<T>>;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    gen(0, 0, 0);

    sort(super_lucky.begin(), super_lucky.end());
    cout << *lower_bound(super_lucky.begin(), super_lucky.end(), n) << endl;
}

