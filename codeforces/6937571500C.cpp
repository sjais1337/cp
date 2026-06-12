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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    cin >> s;

    int n = s.length();
    int count = 0; 
    int curr_num = 0; 

    rep(i,0,n){
        curr_num = (10*curr_num + (s[i]-'0')) % 3;
        if(curr_num == 0 || (s[i]-'0')%3 == 0){
            count++;
            curr_num = 0;
        }
    }

    cout << count << endl;

}

