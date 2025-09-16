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

    vector <vector<int>> a(n);
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j <= i ; j ++) {
            int x;
            cin >> x;
            a[i].push_back(--x);
        }
    }

    int f = 0;
    for (int i = 0 ; i < n ; i++) {
        f = a[max(i, f)][min(i, f)];
    }

    cout << f + 1 << endl;
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