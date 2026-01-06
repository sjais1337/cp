#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << ": " << (x) << "\n"
#define all(vec) (vec).begin(), (vec).end()
#define rAll(vec) (vec).rbegin(), (vec).rend()
#define rep(a, b, c) for (int a = b; a < c; a++)
#define rrep(a, b, c) for (int a = b; a >= c; a--)

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using vec = vector<T>;
template <typename T>
using Matrix = vec<vec<T>>;

constexpr int MOD = 1e9 + 7;

int main()
{
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vec<vec<char>> M(n, vec<char>(n));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> M[i][j];
        }
    }

    int oc = 0;
    rrep(i, n-1, 0)
    {
        rrep(j, n-1, 0)
        {
            if (M[i][j] == '1')
            {
                rep(a, 0, i+1)
                {
                    rep(b, 0, j+1)
                    {
                        M[a][b] = M[a][b] == '1' ? '0' : '1';
                    }
                }
                oc++;
            }
        }
    }

    cout << oc;
}
