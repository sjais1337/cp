#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block {
    int val;
    int rep;
    int prints;
    
    bool operator==(const Block& other) const {
        return val == other.val && rep == other.rep;
    }
};

bool isRepeating(const vector<Block>& v, int len) {
    if (v.size() % len != 0) return false;
    for (int i = len; i < v.size(); i++) {
        if (!(v[i] == v[i % len])) return false;
    }
    return true;
}

vector<Block> compress(const vector<int>& arr) {
    vector<Block> result;
    if (arr.empty()) return result;
    
    int i = 0;
    while (i < arr.size()) {
        int val = arr[i];
        int count = 1;
        while (i + count < arr.size() && arr[i + count] == val) {
            count++;
        }
        result.push_back({val, count, 1});
        i += count;
    }
    return result;
}

vector<Block> recurse(vector<Block>& blocks) {
    int n = blocks.size();
    if (n <= 1) return blocks;
    
    vector<Block> result;
    int pos = 0;
    
    while (pos < n) {
        int max_len = (n - pos) / 2;
        bool found = false;
        
        for (int len = 1; len <= max_len; len++) {
            bool matches = true;
            for (int j = 0; j < len; j++) {
                if (!(blocks[pos + j] == blocks[pos + len + j])) {
                    matches = false;
                    break;
                }
            }
            
            if (matches) {
                for (int j = 0; j < len; j++) {
                    result.push_back(blocks[pos + j]);
                }
                
                pos += len;
                while (pos + len <= n) {
                    bool stillMatches = true;
                    for (int j = 0; j < len; j++) {
                        if (!(blocks[pos + j] == result[result.size() - len + j])) {
                            stillMatches = false;
                            break;
                        }
                    }
                    if (stillMatches) {
                        pos += len;
                    } else {
                        break;
                    }
                }
                
                found = true;
                break;
            }
        }
        
        if (!found) {
            result.push_back(blocks[pos]);
            pos++;
        }
    }
    
    return result;
}

int countPrints(const vector<Block>& blocks) {
    int total = 0;
    for (const auto& b : blocks) {
        total += b.prints;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }

        vector<Block> blocks = compress(arr);

        while(true){
            vector<Block> next = recurse(blocks);
            if(next.size() == blocks.size()){
                break;
            }
            blocks = next;
        }

        int prints = countPrints(blocks);
        
        if(prints <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
