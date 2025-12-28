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
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    int dir = 1;
    int step = 1;
    int tot = 0;
    int c = x;
    
    while(true){
        int next = x + (dir*step);

        if(y >= min(c, next) && y <= max(c, next)){
            tot += abs(y - c);
            break;
        }

        tot += abs(next - c);
        dir *= -1;
        c = next;
        step *= 2;
    }

    cout << tot;
}
