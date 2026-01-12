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
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // if there are intersecting populations, then we cannot form a proper subtree
    map<string, vi> M;
    int n; cin >> n;
    rep(i,0,n){
        int k; cin >> k;
        rep(j,0,k){
            string s; cin >> s;
            M[s].push_back(i);
        }
    }
    map<int,string> rev;
    int c = 0;
    for(auto l: M){
        rev[c] = l.first;c++;
    }
    rep(i,0,M.size()){
        rep(j,i,M.size()){
            vi bigger = M[rev[i]].size() > M[rev[j]].size() ? M[rev[i]] : M[rev[j]]; 
            vi smaller = M[rev[i]].size() <= M[rev[j]].size() ? M[rev[i]] : M[rev[j]]; 

            vi inter;
            for(int k: smaller){
                if(find(bigger.begin(),bigger.end(), k) != bigger.end()){
                    inter.push_back(k);
                }
            }

            if(inter.size() == 0){
                continue;
            }
            
            bool is_subset = true;
            for(int k: smaller){
                if(find(inter.begin(), inter.end(), k) == inter.end()){
                    is_subset = false;
                    break;
                }
            }

            if(!is_subset){
                cout << "no"<<endl;
                return 0;
            }
        }
    }

    cout << "yes"<<endl;
}
