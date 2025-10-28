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

void solve()
{   
    int n;
    string s;
    cin >> n >> s;

    int ans = 1e6;

    vector <vector<int>> odd(26 , vector <int>(n + 2 , 0)) , even(26 , vector <int>(n + 2 , 0));

    for (int c = 0 ; c < 26 ; c ++)
    {
        for (int i = 1 ; i <= n ; i ++)
        {
            if (i & 1)
                odd [c][i] = (s[i - 1] != (c + 'a'));
            else 
                even[c][i] = (s[i - 1] != (c + 'a'));
            
            odd [c][i] += odd [c][i - 1];
            even[c][i] += even[c][i - 1];
        }
    }

    for (int c1 = 0 ; c1 < 26 ; c1 ++)
    {
        for (int c2 = 0 ; c2 < 26 ; c2 ++)
        {
            ans = min(ans , even[c1][n] + odd[c2][n] + n % 2);
            
            for (int i = 1 ; i <= n && n & 1 ; i ++)
            {
                ans = min(ans , even[c1][i - 1] + odd [c1][n] - odd [c1][i]
                              + odd [c2][i - 1] + even[c2][n] - even[c2][i] + 1);
            }
        }
    }

    cout << ans << endl;
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