#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <string> s(n);
    for (auto &x : s)
        cin >> x;

    vector <int> cnt(n);
    int row = -1 , mx = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            cnt[i] += (s[i][j] == '#');
        }

        if (cnt[i] > mx)
            mx = cnt[i] , row = i;
    }

    int c = 0;

    for (int j = 0 ; j < m ; j ++)
    {
        c += (s[row][j] == '#');

        if (c == (cnt[row] + 1) / 2)
        {
            cout << row + 1 << " " << j + 1 << endl;;
            return ;
        }
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}