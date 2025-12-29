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
    int n;
    cin >> n;

    vec<char> dir(n);
    vi num(n);

    for(int i = 0; i < n; i++){
        cin >> dir[i];
        cin >> num[i];
    } 

    int liars = INT_MAX;
    for(int i=0;i<n;i++){
        int ro = 0;
        for(int j=0;j<n;j++){
            if(dir[j] == 'G' && num[i] < num[j]) ro++;
            if(dir[j] == 'L' && num[i] > num[j]) ro++;
        }
        liars = min(ro,liars);
    }

    cout << liars << endl;
}

