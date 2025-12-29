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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vec<vec<int>> field(2001, vector<int>(2001, 0));
    int x = 1000, y = 1000;

    field[x][y]=-1;
    int t = 0;
    int n;
    cin >> n;


    int re = INT_MAX;
    for(int i = 0; i < n; i++) {
        char dir; int m;
        cin >> dir >> m;
        int x_mul = 0, y_mul = 0;
        if(dir == 'N'){
            y_mul = 1;
        }else if(dir == 'S'){
            y_mul = -1;
        }else if(dir == 'E'){
            x_mul = 1;
        }else if(dir == 'W'){
            x_mul = -1;
        }
        for(int j = 0; j < m; j++){
            x += x_mul;
            y += y_mul;
            t++;
            if(field[x][y] != 0){
                re = min(re, t - field[x][y]);
            }
            field[x][y] = t;
        }
    }

    cout << (re == INT_MAX ? -1 : re) << endl;
}
