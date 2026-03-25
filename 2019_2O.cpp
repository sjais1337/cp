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

void solve()

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vec<vi> graph(n);
    vec<vi> rgraph(n);
    rep(i,0,n){
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        rgraph[b-1].push_back(a-1);
    }

    rep(i,0,n){
        
    }
    return 0;
}
