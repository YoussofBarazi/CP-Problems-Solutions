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
    string s;
    cin >> s;

    if (s.size() < 3 || (s[0] - '0') * 10 + s[1] - '0' != 10 || s[2] == '0')
    {
        cout << "NO" << endl;
        return ;
    }

    int x = 0 , p = 1;
    for (int i = s.size() - 1 ; i >= 2 ; i --)
    {
        x += (s[i] - '0') * p;
        p *= 10;
    }

    if (x >= 2)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
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