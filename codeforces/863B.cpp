#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> weights(2*n);

    for(int i = 0; i< 2*n; i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int min = INT_MAX;

    for(int i = 0; i < 2*n; i++){
        for(int j = i+1; j < 2*n; j++){
            int s = 0;
            int i_v = weights[i];
            int j_v = weights[j];
            weights.erase(weights.begin() + j);
            weights.erase(weights.begin() + i);
            for(int k = 0;  k < 2*n - 2; k+=2){
                s += -weights[k] + weights[k+1];   
            }
            if(s < min){
                min = s;
            }
            weights.insert(weights.begin() + i, i_v);
            weights.insert(weights.begin() + j, j_v);
        }
    }
     
    cout << min << endl;
}

