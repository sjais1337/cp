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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vi nums(n);
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            sum+=nums[i];
        }
        int m = n;
        for(int i=n;i>=1;i--){
            if(sum%i != 0) continue;
            
            int tgt=sum/i;
            int j = 0;
            int p_sum = 0;
            int pts = 0;
            while(j < n){
                p_sum += nums[j];
                if(p_sum == tgt){
                    p_sum = 0;
                    pts++;
                }else if(p_sum > tgt){
                    break;
                }
                j++;
            }

            if(pts==i){
                m = min(m, n-i);
            }
        }
        cout << m << endl;
    }

}

