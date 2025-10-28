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
    int n , m;
    cin >> n >> m;

    vector <vi> a(n);

    for (int i = 0 ; i < n ; i ++)
    {
        a[i].resize(m);

        for (int j = 0 ; j < m ; j ++)
            cin >> a[i][j];
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            int mx = 0;
            for (int t = 0 ; t < 4 ; t ++)
            {
                int I = i + dx[t] , J = j + dy[t];

                if (0 <= I && I < n && 0 <= J && J < m)
                    mx = max(mx , a[I][J]);
            }

            if (a[i][j] > mx)
                a[i][j] = mx;

            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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