#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    set<char> types;
    int n;
    cin >> n;
    vector<char> P(n);
    for(int i = 0; i < n; i++){
        cin >> P[i];
        types.insert(P[i]);
    }

    int m = types.size();
    int start = 0;

    map<char, int> caught;
    int min_len = INT_MAX;
    for(int end = 0; end < n; end++){
        caught[P[end]]++;

        while(caught.size() == m && start <= end){
            min_len = min(min_len, end - start + 1);
            caught[P[start]]--;
            if(caught[P[start]] == 0){
                caught.erase(P[start]);
            }
            start++;
        }
    }

    cout << min_len;
}

