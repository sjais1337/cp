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
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    set<pi> seq;
    for(int i = 0; i < n; i++){
        int s, t, b;
        cin >> s >> t >> b;
        seq.insert(make_pair(s, b));
        seq.insert(make_pair(t, -b));
    }

    int buckets = 0;
    int m = 0;

    for(pi c: seq){
        buckets += c.second;
        m = max(buckets, m);
    }

    cout << m << endl;
}
