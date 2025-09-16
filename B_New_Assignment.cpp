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

const int N = 1000009;

vector<int> GPF(N, 0);

void precalc()
{
    for (int i = 2; i < N; i++)
    {
        if (GPF[i] == 0)
            for (int j = i; j < N; j += i)
                GPF[j] = i;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<char> p(n);

    for (auto &x : a)
    {
        cin >> x;
    }

    map<int, set<int>> freqF;
    map<int, set<int>> freqM;
    map <int , vector <int>> fact;
    vector <int> b = a;
    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];

        int t = a[i];

        if (p[i] == 'F')
        {
            bool add = fact[a[i]].size() == 0;

            while (t > 1)
            {
                int d = GPF[t];

                while (t % d == 0)
                    t /= d;

                freqF[d].insert(i);

                if (add)
                    fact[a[i]].pb(d);
            }

        }
        else 
        {
            bool add = fact[a[i]].size() == 0;

            while (t > 1)
            {
                int d = GPF[t];

                while (t % d == 0)
                    t /= d;

                freqM[d].insert(i);

                if (add)
                    fact[a[i]].pb(d);
            }

        }
    }

    int ans = 0;

    for (auto &x : freqF)
    {
        if (x.S.size() == 2)
        {
            ans += 2;
            x.S.clear();
        }
    }

    for (auto &x : freqM)
    {
        if (x.S.size() == 2)
        {
            ans += 2;
            x.S.clear();
        }
    }
    
    vector <bool> vis(n , false);

    for (int i = 0 ; i < n ; i ++)
    {
        if (a[i] == 1)
        {
            ans ++;
            continue;
        }
        else if (vis[i])
            continue;
        
        vector <int> div = fact[a[i]];

        bool ok = false;
    
        for (auto d : div)
        {
            if (freqF[d].size() + freqM[d].size() == 2)
            {
                int i1 = *freqF[d].begin() , i2 = *freqM[d].begin();

                if (vis[i1] || vis[i2])
                    continue;

                vis[i1] = true;
                vis[i2] = true;
                ok = true;
                break;
            }
        }

        ans += ok;

        if (!ok)
        {
            vis[i] = true;
            ans ++;
        }
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    precalc();

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