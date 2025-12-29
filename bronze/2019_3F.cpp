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
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N;
    cin >> N;
    vi R(N, 0), L(N), U(N);
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        if(t == "off"){
            R[i] = -1;
        }else if(t == "on"){
            R[i] = +1;
        }
        cin >> L[i] >> U[i]; 
    }

    int start_s = -1e9;
    int end_s = 1e9;

    for(int i = 0; i < N; i++){
        if(R[i] == -1){
            start_s -= U[i];
            end_s -= L[i];
            start_s = max(0, start_s);
        }else if(R[i] == +1){
            start_s += L[i];
            end_s += U[i];
        }else{
            start_s = max(start_s, L[i]);
            end_s = min(end_s, U[i]);
        }
    }

    int start_e = -1e6;
    int end_e = 1e6;

    for(int i = N-1; i >= 0; i--){
        if(R[i] == -1){
            start_e += L[i];
            end_e += U[i];
        }else if(R[i] == +1){
            start_e -= U[i];
            end_e -= L[i];
            start_e = max(0, start_e);
        }else{
            start_e = max(start_e, L[i]);
            end_e = min(end_e, U[i]);
        }
    }

    cout << start_e << " " << end_e << endl;
    cout << start_s << " " << end_s << endl;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
