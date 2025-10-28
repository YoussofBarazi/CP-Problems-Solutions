#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector <set<int>> row(n), col(m);

    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < m ; j ++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        r--, c--;
        // 0 , 1
        auto R = row[r].lower_bound(c); // 1
        auto C = col[c].lower_bound(r); // 0
        // cout << q << endl;
        if (R != row[r].end() && *R == c && C != col[c].end() && *C == r) {
            row[r].erase(c);
            col[c].erase(r);
            // cout << r << " " << c << endl;
            continue;
        }

        int mn = 1e9;
        vector <pair<int, int>> del;

        if (R != row[r].end()) {
            del.push_back({r, *R});
        } if (R != row[r].begin()) {
            del.push_back({r, *(--R)});
        } if (C != col[c].end()) {
            del.push_back({*C, c});
        } if (C != col[c].begin()) {
            del.push_back({*(--C), c});
        }

        for (auto [i, j] : del) {
            row[i].erase(j);
            col[j].erase(i);
            // cout << i << " " << j << endl;
        }
    }

    int cnt = 0;

    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < m ; j ++) {
            cnt += row[i].count(j) && col[j].count(i);
        }
    }

    cout << cnt << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}