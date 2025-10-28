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

    vector<int> freq(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            freq[i]++;
            n /= i;
        }
    }

    freq[n]++;

    int ans = 1, cnt = 0, c1 = 0, c2 = 0;
    for (int i = 2; i < freq.size(); i++)
    {
        if (freq[i] >= 1)
        {
            ans *= i;
            
            for (int j = 0; j < 22; j++)
            {
                if ((1 << j) >= freq[i])
                {
                    cnt = max(cnt, 1 << j);
                    break;
                }
            }
        }
    }

    for (int i = 2; i < freq.size(); i++)
    {
        if (freq[i] == cnt)
            c1++;
        if(freq[i])
            c2++;
    }

    cnt = ((cnt != 0)? log2(cnt) : 0) + (c1 != c2);

    cout << ans << " " << cnt << endl;
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