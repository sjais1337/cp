#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string str;
int n = 0;

void generate_permutations(vector<int>& chosen, string& temp, vector<string>& buf){
    if(temp.length() == n){
        buf.push_back(temp);
        return;
    }

    for(int i = 0; i < n; i++){
        if(chosen[i]) continue;
        if(i > 0 && str[i] == str[i-1] && !chosen[i-1]) continue;
        chosen[i] = 1;
        temp.push_back(str[i]);
        generate_permutations(chosen, temp, buf);
        chosen[i] = 0;
        temp.pop_back();
    }

}

int main() {
    cin >> str;
    sort(str.begin(), str.end());
    n = str.length();

    vector<int> chosen(n);
    vector<string> buf;
    string temp = "";
    generate_permutations(chosen, temp, buf);
    int len =  buf.size(); 
    cout << len << endl;
    for(int i = 0; i < len; i++){
        cout << buf[i] << endl;
    }
}
