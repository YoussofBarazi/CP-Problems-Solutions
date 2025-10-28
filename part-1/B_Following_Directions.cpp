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
    int n;
    string s;
    cin >> n >> s;

    int x = 0 , y = 0;
    bool ok = false;

    for (int i = 0 ; i < n ; i ++)
    {
        x += s[i] == 'U';
        x -= s[i] == 'D';
        y += s[i] == 'R';
        y -= s[i] == 'L';

        if (x == 1 && y == 1)
            ok = true;
    }

    cout << ((ok) ? "YES" : "NO") << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}