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

    vector <int> a(n);
    vector <bool> used(n , false);

    for (auto &x : a)
        cin >> x;

    int OR = 0 , cnt = 0;

    for (int x = 0 ; x < 30; x ++)
    {
        vector<int> val(n, 0);

        for (int i = 0 ; i < n ; i ++)
        {
            if (used[i])
                continue;

            for (int j = 0 ; j < 30 ; j ++)
            {
                if (OR & (1 << j) || !(a[i] & (1 << j)))
                    continue;

                val[i] += (1 << j);
            }
        }

        int mx = 0 , ndx = 0;
        for (int i = 0 ; i < n ; i ++)
        {
            if (!used[i] && mx <= val[i])
            {
                mx = val[i];
                ndx = i;
            }
        }

        if (cnt == n)
            break;
        
        cout << a[ndx] << " ";
        
        cnt ++;
        
        OR |= a[ndx];
        
        used[ndx] = true;
    }
    
    for (int i = 0 ; i < n ; i ++)
    {
        if (!used[i])
            cout << a[i] << " ";
    }

    cout << endl;
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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}