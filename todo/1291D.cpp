#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(string& t){
    // To determine whether at least one irreducible anagram exists for t.

    // An anagram is irreducible if none of the possible ways to split it
    // into more than or equal to 2 strings results in each of the corres
    // ponding strings to be anagram of each other.

    // Bruteforce Approach: Go through all the anagrams of the string t, 
    // for each anagram, split it into all possible split, and then chec
    // if the corresponding splits formed are anagrams of the splits tha
    // t would be formed from t. 

    // This is a very very inefficient approach, worst case complexity po
    // sibly 10^30 or something. Need to figure out something much better.

        
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string t;
    int q;
    cin >> t;

    while(q--){
        int l, r;
        cin >> l >> r;
        string sub = t.substr(l-1, r-l+1);
        
        solve(sub);
    }
}

