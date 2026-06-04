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
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vi ind(n,-1);
    vi ord(m);
    vi used(n,-1);
    for(int i = 0;i<m;i++){
        cin >> ord[i];
        ord[i]--;
    }
    for(int i = 0;i<k;i++){
        int c; cin >>c;
        c--;
        int temp; cin >> temp;
        temp--;
        used[c]=temp;
        if(c==0) {
            cout << temp+1 << endl;
            return 0;
        } 
        ind[temp]=c;
    }

    rep(i,0,n){
        vi vind(ind.begin(),ind.end());
        vi vord(ord.begin(), ord.end());
        vi vused(used.begin(), used.end());
        if(vind[i]!=-1) continue;
        vused[0]=i;
        vind[i]=0;
        int mi = 0;
        rep(j,0,n){
            if(vind[j]!=-1) continue;
            if(mi==0) {
                vind[j]=vord[mi]; continue;
            }
            if(vused[vord[mi-1]] > j) continue;
            vused[vord[mi]] = j;
            vind[j]=vord[mi];
            mi++;
        }
        if(mi<m){
            continue;
        }
        cout << i+1 << endl;
        return 0;
    } 
}
