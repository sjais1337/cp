#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Standard USACO file I/O
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int N;
    if (!(cin >> N)) return 0;

    // {milk_output, count}
    vector<pair<int, int>> cows(N);
    for(int i = 0; i < N; i++){
        cin >> cows[i].second >> cows[i].first;
    }

    // Sort by milk output (the 'y' in your original code)
    sort(cows.begin(), cows.end());

    int start = 0, end = N - 1;
    int max_time = 0;

    while(start <= end) {
        // If pointers meet, the cow(s) pair with themselves (or others in their group)
        if (start == end) {
            max_time = max(max_time, cows[start].first * 2);
            break;
        }

        int pair_count = min(cows[start].second, cows[end].second);
        max_time = max(max_time, cows[start].first + cows[end].first);

        cows[start].second -= pair_count;
        cows[end].second -= pair_count;

        if(cows[start].second == 0) start++;
        if(cows[end].second == 0) end--;
    }

    cout << max_time << endl;
    return 0;
}