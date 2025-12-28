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
    vec<pi> it;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        it.push_back(make_pair(-1, a));
        it.push_back(make_pair(-2, b));
    }
    sort(it.begin(), it.end(), [](pi a, pi b){return a.second < b.second;});
    int tot = 0;
    int m = 0;
    for(int i = 0; i < it.size(); i++){
        if(it[i].first == -1) tot++;
        if(it[i].first == -2) tot--;
        m = max(m, tot);
    }

    cout << m << endl;
}

