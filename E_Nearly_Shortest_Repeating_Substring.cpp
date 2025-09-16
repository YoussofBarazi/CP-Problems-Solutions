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

vector <int> v[N];

void precalc()
{
    for (int i = 1 ; i < N ; i ++)
        for (int j = i ; j < N ; j += i)
            v[j].push_back(i);
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    
    for (auto d : v[n])
    {
        string c = s.substr(0 , d);
        int cnt = 0;

        for (int i = 0 ; i < n ; i ++)
        {
            cnt += (c[i % d] != s[i]);
            if (cnt > 1)
                break;
        }

        if (cnt <= 1)
        {
            cout << d << endl;
            return ;
        }

        c = s.substr(n - d , d);
        cnt = 0;

        for (int i = 0 ; i < n ; i ++)
        {
            cnt += (c[i % d] != s[i]);
            if (cnt > 1)
                break;
        }

        if (cnt <= 1)
        {
            cout << d << endl;
            return ;
        }
    }
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