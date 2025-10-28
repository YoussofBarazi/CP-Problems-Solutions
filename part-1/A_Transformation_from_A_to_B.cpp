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

int a, b;

vector<int> ans;

void solve()
{
    cin >> a >> b;

    ans = {b};

    bool ok = false;

    while (a < b)
    {
        if (b % 2 == 1 && b % 10 != 1)
            break;
            
        if (b & 1)
        {
            b /= 10;
        }
        else 
        {
            b /= 2; 
        }

        if (a == b)
            ok = true;

        ans.pb(b);        
    }

    if (ok)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int i = ans.size() - 1 ; i >= 0 ; i --)
            cout << ans[i] << " ";
    }
    else 
    {
        cout << "NO" << endl;
    }
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}