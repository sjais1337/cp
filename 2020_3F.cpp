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
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // treat this as a graph. the nodes are the numbers. two nodes
    // are adjacent if there is an edge between them. add two extr
    // a nodes which represent the start and end of the graph/chai
    // n and thus this will help us print the entire chain once do
    // ne. 

    int n, k;
    cin >> n >> k;
    vec<pair<int,int>> edges;

    rep(i,0,n){
        edges.push_back({i,i+1});
    }
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    for(int i = 0; i < k; i++){
        // store edges as {L, R} 
        // 1 to 6
        // 0 1
        // 6 2 - 1
        // 2 3
        // 3 4
        // 4 5
        // 5 1 - 5
        // 6 7
        int temp = edges[a1-1].first;
        edges[a1-1].first = edges[a2].second;
        edges[a2].second = temp;
        
        temp = edges[b1-1].first;
        edges[b1-1].first = edges[b2].second;
        edges[b2].second = temp;
    }

    vec<vi> graph;
    rep(i,0,n){
        int a = edges[i].first;
        int b = edges[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 1;
    int last = graph[0][0];
    while(count != n){
        // any element can have at most two nodes that it is connected to 
        // we'll start iterating from 0, and check if an element is the e
        // lement we have reached it from

        cout << last << endl;

        set<int> temp(graph[last].begin(), graph[last].end());
        temp.erase(last);

        last = (*(temp.begin()));
        count++;
    }

    return 0;
}
