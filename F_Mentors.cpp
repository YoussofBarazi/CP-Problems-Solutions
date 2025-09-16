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
    vector <int> r(n) , skills;

    for (auto &x : r)
        cin >> x;
    
    skills = r;

    for (int i = 0 ; i < m ; i ++)
    {
        int x , y;
        cin >> x >> y;
        x -- , y --;

        if (r[x] > r[y])
            a[x].push_back(y);
        if (r[y] > r[x])
            a[y].push_back(x);
    }

    sort(all(skills));

    for (int i = 0 ; i < n ; i ++)
    {
        int l = -1 , h = n - 1;

        while (l + 1 < h)
        {
            int mid = (l + h) / 2;

            if (skills[mid] < r[i])
                l = mid;
            else 
                h = mid;
        }

        int ans = l - a[i].size() + 1;

        cout << ans << " ";
    }
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