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

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    sort(all(a));
    set <int> ans;

    if (n == 1)
    {
        cout << -1 << endl;
    }
    else if (n == 2)
    {
        ans = {2 * a[0] - a[1] , 2 * a[1] - a[0]};

        if ((a[1] - a[0]) % 2 == 0)
        {
            ans.insert((a[1] + a[0]) / 2);
        }
        
        cout << ans.size() << endl;
        for (auto x : ans)  
            cout << x << " ";
    }
    else
    {
        int x = 0, cnt = 0;
        bool ok = false;
        set<int> s;

        for (int i = 1; i < n; i++)
        {
            s.insert(a[i] - a[i - 1]);
        }

        if (s.size() < 2)
        {
            ans = {2 * a[0] - a[1] , 2 * a[n - 1] - a[n - 2]};

            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x << " ";
        }
        else
        {
            int mn = *s.begin(), mx = *s.rbegin();

            for (int i = 1; i < n; i++)
            {
                if (a[i] - a[i - 1] == mx)
                {
                    if ((a[i] - a[i - 1]) != mn * 2)
                    {
                        cout << 0 << endl;
                        return ;
                    }
                    
                    cnt ++;
                    x = a[i] - mn;
                }
            }

            if (cnt == 1)
            {
                cout << 1 << endl << x << endl;
            }
            else 
            {
                cout << 0 << endl;
            }
        }
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