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

bool solve(int step, int n, vi& coloring, vec<vi>& graph){
    for(int a: graph[step+1]){
        if(a-1 < step && coloring[a-1]==coloring[step]){
            return false;
        }
    }

    if(step == n-1){
        for(int c: coloring){
            cout << c;
        }
        cout << endl;
        return true;
    }

    for(int i = 1; i<=4;i++){
        coloring[step+1]=i;
        if(solve(step+1,n,coloring, graph)){
            return true;
        }
    }

    return false;
}


int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N pastures, M cows. 

    // Each cow can be represented as an edge between two pastures
    // No two connected pasture must have the same color, and thus
    // a pasture can't be a favorite of more than 3 cows, since th
    // ere can only be at most 3 edges connected to each pasture. 
    // we have to find a valid coloring of the graph using 4 color

    // a algorithm which will work is to start from a pasture 1, & 
    // assign it a color, and then start a recursion kind of thing
    // for the next pasture, and at each step check if any of the 
    // pastures from 1 to n are connected, and have the same type, 
    // if yes then break, else keep going. If we reach the end, th
    // en we have found a coloring which works.

    int n, m;
    cin >> n >> m;
    vec<vi> graph(n+1);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi coloring(n, 0);
    for(int i = 1; i<=4;i++){
        coloring[0]=i;
        if(solve(0,n,coloring, graph)){
            break;
        }
    }
    return 0;
}
