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
    
    int n; cin >> n;
    vi vals(n);
    rep(i,0,n) cin >> vals[i];

    int a = vals[n-1];
    int sum = vals[n-1];

    rrep(i,n-2,0){
        // at any step, if the player chooses to "give" then their payoff
        // becomes the payoff of the next player, and they still are the 
        // next player and if they choose to take, then their payoff becomes 
        // payoff of eating current slice + (sum - the other player payoff)
        int payoff_give, payoff_take;

        payoff_give = a;
        payoff_take = vals[i] + (sum - a);

        a = max(payoff_give, payoff_take);

        sum += vals[i];
   }

   cout << (sum - a) << " " << a;
}

