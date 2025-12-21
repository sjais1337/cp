#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// void recursive_search(vector<int>& v, int i, int n){
//     if(i == n){
//         for(int j = 0; j < subset.size(); j++){
//             cout << subset[j] << " ";
//         }
//         cout << endl;
//     }else{
//         recursive_search(v, i + 1, n);
//         subset.push_back(v[i]);
//         recursive_search(v, i + 1, n);
//         subset.pop_back();
//     }
// }

int main() {
    int n;

    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    
    for(int i = 0; i < (1<<n); i++){
        for(int b = 0; b < n; b++){
            if((1<<b)&i) cout << numbers[b] << " ";
        }
        cout << endl;
    }

    return 0;
}
