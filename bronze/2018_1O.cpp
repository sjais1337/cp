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
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> cows;

    vec<vec<char>> toe(3, vec<char>(3));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> toe[i][j]; 
            cows.insert(toe[i][j]);
        }
    }

    int one = 0;
    for(char b: cows){
        int won = 0;
        for(int i = 0; i < 3; i++){
            set<char> cos;
            for(int j =0; j<3;j++){
                cos.insert(toe[i][j]);
            }
            cos.erase(b);
            if(cos.size() == 0) {
                won=1;
            }
        }
        
        for(int i = 0; i < 3; i++){
            set<char> cos;
            for(int j =0; j<3;j++){
                cos.insert(toe[j][i]);
            }
            cos.erase(b);
            if(cos.size() == 0) {
                won=1;
            }
        }


        set<char> cos1;
        set<char> cos2;
        for(int i = 0; i < 3; i++){
            cos1.insert(toe[i][i]);
        }
        cos1.erase(b);
        if(cos1.size() == 0){
            won = 1;
        } 
        
        for(int i = 0; i < 3; i++){
            cos2.insert(toe[i][2-i]);
        }
        cos2.erase(b);
        if(cos2.size() == 0){
            won = 1;
        } 
        
        one = one + won;
    }

    int two = 0;
    for(char a: cows){
        for(char b: cows){
            if(a >= b) continue;

            int won = 0;
            for(int i = 0; i < 3; i++){
                set<char> cos;
                for(int j =0; j<3;j++){
                    cos.insert(toe[i][j]);
                }
                if(cos.size() == 2 && cos.count(a) && cos.count(b)){
                    won=1;
                }
            }
            
            for(int i = 0; i < 3; i++){
                set<char> cos;
                for(int j =0; j<3;j++){
                    cos.insert(toe[j][i]);
                }
                if(cos.size() == 2 && cos.count(a) && cos.count(b)){
                    won=1;
                }
            }


            set<char> cos1;
            set<char> cos2;
            for(int i = 0; i < 3; i++){
                cos1.insert(toe[i][i]);
            }
            if(cos1.size() == 2 && cos1.count(a) && cos1.count(b)){
                won = 1;
            } 
            
            for(int i = 0; i < 3; i++){
                cos2.insert(toe[i][2-i]);
            }
            if(cos2.size() == 2 && cos2.count(a) && cos2.count(b)){
                won = 1;
            } 
            
            two = two + won;
        }
    }

    cout << one << endl;
    cout << two << endl;
}
