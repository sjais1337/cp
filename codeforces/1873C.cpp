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
        int score = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                char a;
                cin >> a;
                if(a == 'X'){
                    if(i == 0 || i == 9 || j == 0 || j == 9){
                        score++;
                    }else if(i == 1 || i == 8 || j == 1 || j == 8){
                        score += 2;
                    }else if(i == 2 || i == 7 || j == 2 || j == 7){
                        score += 3;
                    }else if(i == 3 || i == 6 || j == 3 || j == 6){
                        score += 4;
                    }else{
                        score += 5;
                    }
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}

