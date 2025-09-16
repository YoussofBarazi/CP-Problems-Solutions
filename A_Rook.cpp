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
    string s;
    cin >> s;

    int r = s[1] - '0' , c = s[0] - 'a';

    for (int i = r + 1 ; i <= 8 ; i ++)
    {
        cout << s[0] << (i) << endl; 
    }

    for (int i = r - 1 ; i >= 1 ; i --)
    {
        cout << s[0] << i << endl;
    }

    for (int i = c + 1 ; i < 8 ; i ++)
    {
        cout << char(i + 'a') << s[1] << endl;
    }

    for (int i = c - 1 ; i >= 0 ; i --)
    {
        cout << char(i + 'a') << s[1] << endl;
    }
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