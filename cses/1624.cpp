#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int DIM = 8;
  vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
  for (int i = 0; i < DIM; i++) {
    string row;
    cin >> row;
    for (char c = 0; c < DIM; c++) {
      blocked[i][c] = (row[c] == '*');
    }
  }

  vector<int> queens(DIM);
  iota(queens.begin(), queens.end(), 0);

  int options = 0;
  do {
    bool works = true;
    for (int c = 0; c < DIM; c++) {
      if (blocked[queens[c]][c]) {
        works = false;
        break;
      }
    }

    vector<bool> taken(2 * DIM - 1);
    for (int c = 0; c < DIM; c++) {
      if (taken[queens[c] + c]) {
        works = false;
        break;
      }
      taken[queens[c] + c] = true;
    }

    taken = vector<bool>(2 * DIM - 1);
    for (int c = 0; c < DIM; c++) {
      if (taken[queens[c] - c + DIM - 1]) {
        works = false;
        break;
      }
      taken[queens[c] - c + DIM - 1] = true;
    }

    if (works) {
      options++;
    }
  } while (next_permutation(queens.begin(), queens.end()));

  cout << options << endl;
}
