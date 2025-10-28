#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

bool possible[N];

void precalc()
{
    for (int x = 1 ; x <= 1e5 ; x ++)
    {
        for (int i = 1 ; i * i <= x ; i ++)
        {
            if (x % i == 0)
            {
                bool ok = true;
                
                int t = i;
                while (t > 0)
                    ok &= (t % 10) <= 1 , t /= 10;

                t = x / i;
                while (t > 0)
                    ok &= (t % 10) <= 1 , t /= 10;

                if (ok || (possible[i] && possible[x / i]))
                {    
                    possible[x] = true;
                    break;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    cout << ((possible[n])? "YES" : "NO") << endl;
}

int main()
{
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