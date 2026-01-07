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
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; vi dists(n);
    rep(i,0,n){
        cin >> dists[i];
    }
    sort(dists.begin(),dists.end());
    // the people who will be passed balls by at least someone
    // do not need the ball, so we just give balls to those wh
    // o won't be passed balls by anyone else
    vi passed(n,0);
    rep(i,0,n){
        vi arr;
        arr.push_back(i-2>=0?dists[i-2]:-5000);
        arr.push_back(i-1>=0?dists[i-1]:-3000);
        arr.push_back(dists[i]);
        arr.push_back(i+1<=n-1?dists[i+1]:3000);
        arr.push_back(i+2<=n-1?dists[i+2]:6000);
        if(arr[1]-arr[0]>arr[2]-arr[1]) passed[i]++;
        if(arr[3]-arr[2]<=arr[4]-arr[3]) passed[i]++;
    }
    int tot = 0;
    for(int c: passed){
        if(c<2) tot++;
    }
    cout << tot << endl;
}
