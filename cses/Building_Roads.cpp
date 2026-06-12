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

int counta = 0;

void dfs(int c, vec<vi>& adj, vi& visited){
    if(visited[c]) return;
    visited[c] = 1;

    for(int& n: adj[c]){
        dfs(n, adj, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; int m;
    cin >> n >> m;

    vec<vi> adj(n+1);

    rep(i,0,m){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi visited(n+1, 0);
    vi edges;

    dfs(1, adj, visited);

    rep(i,2,n+1){
        if(!visited[i]){
            adj[1].push_back(i);
            adj[i].push_back(1);

            edges.push_back(i);

            dfs(i,adj,visited);
        }
    }

    cout << edges.size() << endl;

    for(int& c: edges){
        cout << 1 << " " << c << endl;
    }
}

