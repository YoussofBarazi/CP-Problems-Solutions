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

int ans[N]; 
int a[N];
string s;


void solve()
{
    int n;
    cin >> n;

    vector <int> a(n);
    
    for (int &i : a)
    {          
        cin >> i;
        i --;
    }
    cin >> s;

    vector <int> ans(n , 0);
    vector <bool> vis(n , false);

    for (int i = 0 ; i < n ; i ++)
    {
        if (vis[i])
            continue;

        int ndx = i;
        int cnt = 0;
        bool t = false;
        vector <int> path;

        while (true)
        {
            path.push_back(ndx);
            cnt += s[ndx] == '0';

            if (a[ndx] == ndx)
                break;
            else if (vis[a[ndx]])
            {    
                cnt += ans[a[ndx]];
                t = true;
                break;
            }
            vis[ndx] = true;
            ndx = a[ndx];
        }
        vis[ndx] = true;

        for (auto x : path)
        {
            ans[x] = cnt;

            if (!t)
                cnt -= (s[x] == '0');
        }
    }

    for (int i = 0 ; i < n ; i ++)
        cout << ans[i] << " ";
    cout << endl;
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