#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, n;
    cin >> k >> n;
    vector<int> A(k);
    set<int> B;

    for(int i = 0; i < k; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        int temp; 
        cin >> temp;
        B.insert(temp);
    }

    set<ll> valid_x;

    // For each b in B, assume it appears at position j (0-indexed)
    // Score after j-th jury = x + A[0] + A[1] + ... + A[j] = b
    // So x = b - (A[0] + ... + A[j])
    
    for(const int& b : B){
        ll sum = 0;
        for(int j = 0; j < k; j++){
            sum += A[j];
            ll x = b - sum;  // candidate initial score
            
            // Now verify: check that all scores in B appear among the k announced scores
            // and count how many of them match
            ll curr_score = x;
            int matched = 0;
            
            for(int l = 0; l < k; l++){
                curr_score += A[l];
                if(B.count(curr_score)){
                    matched++;
                }
            }
            
            // All n remembered scores must appear in the k announced scores
            if(matched == n){
                valid_x.insert(x);
            }
        }
    }

    cout << valid_x.size() << endl;
    return 0;
}