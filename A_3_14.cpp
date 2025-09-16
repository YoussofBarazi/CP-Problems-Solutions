#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n;
    cin >> n;

    string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    for (int i = 0; i < n + 2; i++)
        cout << s[i];
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