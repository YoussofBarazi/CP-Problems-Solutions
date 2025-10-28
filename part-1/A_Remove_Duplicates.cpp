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

    vector <int> a(1001 , -1);
    vector <pii> t;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        a[x] = i;
    }

    for (int i = 1 ; i <= 1000 ; i ++)
    {
        if (a[i] == -1)
            continue;
        t.push_back({a[i] , i});
    }

    sort(all(t));

    cout << t.size() << endl; 
    for (auto x : t)
        cout << x.S << " ";
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