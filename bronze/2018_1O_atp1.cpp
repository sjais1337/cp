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
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char toe[3][3];
    for(int i =0; i< 3; i++){
        for(int j =0; j<3; j++){
            cin >> toe[i][j];
        }
    }

    set<char> one;
    set<set<char>> two;

    auto check = [&](vector<char> line){
        set<char> s(line.begin(), line.end());
        if(s.size() == 1){
            one.insert(*s.begin());
        }else if(s.size() == 2){
            two.insert(s);
        }
    };
    for(int i =0; i<3; i++) check({toe[i][0], toe[i][1], toe[i][2]});
    for(int i =0; i<3; i++) check({toe[0][i], toe[1][i], toe[2][i]});

    check({toe[0][0], toe[1][1],toe[2][2]});
    check({toe[2][0], toe[1][1],toe[0][2]});

    cout << one.size() << endl;
    cout << two.size() << endl;

}
