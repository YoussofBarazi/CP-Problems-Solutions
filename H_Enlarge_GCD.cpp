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

const int N = 1.5e7 + 9;

vector <int> GPF(N , 0);
vector <int> freq(N , 0);

void calc()
{
    GPF[1] = GPF[0] = 1e9;

    for (int i = 2; i < N; i++)
    {
        if (!GPF[i])
        {
            for (int j = i; j < N; j += i)
            {
                GPF[j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int GCD = 0;
    
    for (auto &x : a)
    {
        cin >> x;
        GCD = gcd(GCD , x);
    }

    calc();

    for (auto t : a)
    {
        int x = t / GCD;

        while (x > 1)
        {
            int g = GPF[x];    
            freq[g] ++;
            
            while (x % g == 0)
                x /= g;
        }
    }

    int ans = n;

    for (int i = 0 ; i < N ; i ++)
    {
        if (i == GPF[i] && freq[i])
        {
            ans = min (ans , n - freq[i]);
        }
    }

    if (ans == n)
        ans = -1;

    cout << ans << endl;
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