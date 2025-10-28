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
    for (auto &x : a)
        cin >> x;

    int m;
    cin >> m;

    while (m --)
    {
        string s;
        cin >> s;

        if (s.size() != n)
        {
            cout << "NO" << endl;
            continue;
        }

        bool ok = true;
        vector <int> x(26 , INT_MIN);
        map <int , int> xx;
        for (int i = 0 ; i < n ; i ++)
        {
            if (x[s[i] - 'a'] == INT_MIN && xx.count(a[i]) == 0)
                x[s[i] - 'a'] = a[i] , xx[a[i]] = s[i];
            else if (x[s[i] - 'a'] != a[i] || xx[a[i]] != s[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
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