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

    int n;cin>>n;
    vi a(n);
    vi b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    } 
    int init_c = 0;
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(b[i]==a[i]) init_c++;
    } 
    vi ops(n+1,0);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ct = init_c;
            for(int k=i;k<=j;k++){
                if(a[i+j-k]==b[k]) ct++;
                if(a[k]==b[k]) ct--;
            }

            ops[ct]++;
        }
    }
    for(int c: ops){
        cout << c << endl;
    }
}

