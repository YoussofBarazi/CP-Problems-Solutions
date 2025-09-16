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
    cin >> n;

    vector <int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = 2e5;

    for (int x = -1; x < 2; x++)
    {
        for (int y = -1 ; y < 2 ; y++)
        {
            int diff = a[1] + y - (a[0] + x);
            int res = abs(y) + abs(x);
            int change = y;

            for (int i = 2 ; i < n ; i ++)
            {
                int cur = a[i] , prev = a[i - 1] + change;

                if (cur - prev + 1 == diff)
                    change = 1 , res ++;
                else if (cur - prev - 1 == diff)
                    change = -1 , res ++;
                else if (cur - prev == diff)
                    change = 0;
                else 
                {
                    res = 2e5;
                    break;
                }
            }

            ans = min(ans , res);
        }
    }
    
    cout << ((ans == 2e5)? -1 : ans) << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}