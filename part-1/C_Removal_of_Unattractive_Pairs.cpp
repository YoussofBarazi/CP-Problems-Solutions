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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector <int> freq(27 , 0);
    for (auto x : s)
        freq[x - 'a'] ++;

    int ind = 0 , mx = 0;

    for (int i = 0 ; i < 27 ; i ++)
    {
        if (freq[i] > mx)
            mx = freq[i] , ind = i;
    }

    for (int i = 0 ; i < 27 ; i ++)
    {
        if (i != ind)
            mx -= freq[i];
    }

    if (mx > 0)
        cout << mx << endl;
    else 
        cout << n % 2 << endl;
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