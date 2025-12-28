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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    map<int, int> A; 
    for(int i =0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        A[a] += c; 
        A[b] -= c; 
    } 

    vec<pair<int, ll>> B;
    if(!A.count(0)) B.push_back(make_pair(0, 0));
    for(auto &c: A){
        pi temp;
        if(B.begin() != B.end()){
            temp = *prev(B.end());  
        }else{
            temp = make_pair(0,0);
        }
        B.push_back(make_pair(c.first, temp.second + c.second));
    }
    
    vec<pi> qs(q);
    set<int> T;
    T.insert(0);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        qs[i] = {a, b};
        T.insert(a);
        T.insert(b);
    }

    vi Q(T.begin(), T.end());

    map<int, ll> ps;

    auto prev_it = B.begin();
    int last_pos = 0;
    ll tot = 0;
    ps[0] = 0;

    for(int i = 0; i < Q.size(); i++){
        int pos = Q[i];

        auto fin_it = lower_bound(B.begin(), B.end(), make_pair(pos, (ll) -1));

        while(last_pos < pos){
            auto next_it = next(prev_it);

            int change = (next_it == B.end()) ? pos : next_it->first;
            change = min(change, pos);

            ll len = change - max(last_pos, prev_it->first);

            if(len > 0){
                tot += len * prev_it->second;
                last_pos = change;
            }

            if(next_it != B.end() && last_pos >= next_it->first){
                prev_it++;
            }else{
                break;
            }
        }

        ps[pos] = tot;
    }


    for(int i = 0; i < q; i++){
        int a = qs[i].first;
        int b = qs[i].second;

        cout << ps[b] - ps[a] << endl;
    }

    return 0;
}

