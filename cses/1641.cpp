#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll C;

    cin >> n >> C;

    vector<pair<ll, int>> A;

    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;
        A.push_back({temp, i});
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < n-1; i++){
        int start = i+1, end = n-1;
        int B = C - A[i].first;
        
        while(start != end){
            int xpy = A[start].first + A[end].first;

            if(xpy > B){
                end--;
            }else if(xpy < B){
                start++;
            }else{
                cout << A[i].second + 1<< " " << A[start].second + 1<< " " << A[end].second + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

