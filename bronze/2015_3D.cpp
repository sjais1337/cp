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
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,d,s;
    cin >> n >> m >> d >> s;

    vec<tuple<int,int,int>> pmt(d);
    set<pair<int,int>> pm;

    for(int i=0;i<d;i++){
        int p, m, t;
        cin >> p >> m >> t;
        pmt[i] = make_tuple(p,m,t);
        pm.insert({p,m});
    }
    sort(pmt.begin(), pmt.end(), [](tuple<int,int,int> a, tuple<int,int,int> b){
        return get<2>(a) < get<2>(b);
    });

    vi ba(m);
    iota(ba.begin(), ba.end(), 1);
    set<int> bmilk(ba.begin(), ba.end());

    for(int i=0;i<s;i++){
        int p, t;
        cin >> p >> t;

        set<int> bmilk_l;
        for(auto& it: pmt){
            if(get<0>(it) == p && get<2>(it) < t){
                bmilk_l.insert(get<1>(it));
            }
        }

        for(auto ita = bmilk.begin(); ita!=bmilk.end();){
            if(!bmilk_l.count(*ita)) {
                ita = bmilk.erase(ita);
            }else{
            ita++;
            }
        }
    }

    int min_dose = 0;
    for(int c: bmilk){
        int dose = 0;
        for(pi x: pm){
            if(x.second == c){
                dose++;
            }
        }
        min_dose = max(dose, min_dose);
    }

    cout << min_dose << endl;
}
