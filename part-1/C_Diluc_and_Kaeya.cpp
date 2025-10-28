#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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
    string s;
    cin >> n >> s;

    int cntD = 0, cntK = 0;
    map<pair<int, int>, int> m;
    for (size_t i = 0; i < n; i++)
    {
        cntD += s[i] == 'D';
        cntK += s[i] == 'K';

        m[{cntD / gcd(cntD, cntK), cntK / gcd(cntD, cntK)}]++;
        cout << m[{cntD / gcd(cntD, cntK), cntK / gcd(cntD, cntK)}] << " ";
    }
    cout << endl;
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