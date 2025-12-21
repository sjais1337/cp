#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Logo {
  int x;
  int y;
  char i;
};

int main() {
  Logo initial[3];
  vector<int> order = {0, 1, 2};
  for (int i = 0; i < 3; i++) {
    cin >> initial[i].x;
    cin >> initial[i].y;
    initial[i].i = 'A' + i;
  }

  do {
    for (int i = 0; i < 8; i++) {

      Logo dim[3];
      for (int j = 0; j < 3; ++j) {
        dim[j] = initial[order[j]];
      }

      for (int j = 0; j < 3; j++) {
        if ((i >> j) & 1) {
          swap(dim[j].x, dim[j].y);
        }
      }

      // Two possible configurations, all vertical and
      // one and two stacked.

      if ((dim[0].x == dim[1].x) && (dim[1].x == dim[2].x) &&
          (dim[0].y + dim[1].y + dim[2].y == dim[0].x)) {
        cout << dim[0].x << endl;

        for (int k = 0; k < dim[0].y; k++) {
          cout << string(dim[0].x, dim[0].i) << endl;
        }
        for (int k = 0; k < dim[1].y; k++) {
          cout << string(dim[1].x, dim[1].i) << endl;
        }
        for (int k = 0; k < dim[2].y; k++) {
          cout << string(dim[2].x, dim[2].i) << endl;
        }

        return 0;
      }

      if ((dim[0].x + dim[1].x == dim[0].y) && (dim[1].x == dim[2].x) &&
          (dim[1].y + dim[2].y == dim[0].y)) {

        cout << dim[0].y << endl;

        for (int k = 0; k < dim[1].y; k++) {
          cout << string(dim[0].x, dim[0].i) << string(dim[1].x, dim[1].i)
               << endl;
        }
        for (int k = 0; k < dim[2].y; k++) {
          cout << string(dim[0].x, dim[0].i) << string(dim[2].x, dim[2].i)
               << endl;
        }
        return 0;
      }

      if ((dim[0].y + dim[1].y == dim[0].x) && (dim[1].y == dim[2].y) &&
          (dim[1].x + dim[2].x == dim[0].x)) {
        cout << dim[0].x << endl;

        for (int k = 0; k < dim[0].y; k++) {
          cout << string(dim[0].x, dim[0].i) << endl;
        }

        for (int k = 0; k < dim[1].y; k++) {
          cout << string(dim[1].x, dim[1].i) << string(dim[2].x, dim[2].i)
               << endl;
        }

        return 0;
      }

      for (int c : order) {
        if ((1 << c) & i) {
          int temp = dim[c].y;
          dim[c].y = dim[c].x;
          dim[c].x = temp;
        }
      }
    }
  } while (next_permutation(order.begin(), order.end()));

  cout << -1 << endl;
  return 0;
}
