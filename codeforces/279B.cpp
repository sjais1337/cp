#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll t;
    cin >> n >> t;


    vector<int> times(n);

    for(int i = 0; i < n; i++){
        cin >> times[i];
    }

    // for each subarray, check if max < length
    // if yes, check if sum of elements <= t then
    // max = len;

    int start = 0;
    int max = 0;
    
    ll c = 0;

    for(int end = 0; end < n; end++){
        c += times[end];

        while(c > t && start <= end){
            c -= times[start];
            start++;
        }

        int len = end - start + 1;
        if(len > max){
            max = len;
        }
    }
    cout << max << endl;
}

