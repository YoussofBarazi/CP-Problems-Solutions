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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    vector <string> s(9);

    for (size_t i = 0; i < 9; i++)
    {
        cin >> s[i];
    }
    
    if (s[0][0] == '1') s[0][0] = '2';
    else s[0][0] = '1';
    
    if (s[1][4] == '1') s[1][4] = '2';
    else s[1][4] = '1';

    if (s[3][1] == '1') s[3][1] = '2';
    else s[3][1] = '1';

    if (s[2][8] == '1') s[2][8] = '2';
    else s[2][8] = '1';

    if (s[4][5] == '1') s[4][5] = '2';
    else s[4][5] = '1';

    if (s[5][6] == '1') s[5][6] = '2';
    else s[5][6] = '1';

    if (s[6][2] == '1') s[6][2] = '2';
    else s[6][2] = '1';

    if (s[7][3] == '1') s[7][3] = '2';
    else s[7][3] = '1';

    if (s[8][7] == '1') s[8][7] = '2';
    else s[8][7] = '1';

    for (size_t i = 0; i < 9; i++)
    {
        cout << s[i] << endl;
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