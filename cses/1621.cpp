#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    set<int> s;
    int n;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << endl;
}

