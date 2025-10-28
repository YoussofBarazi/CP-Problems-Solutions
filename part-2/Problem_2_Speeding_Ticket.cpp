#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector<pair<int, int>> speed(103);

int O_O(int i)
{
    if (i == 101)
        return 0;

    return max(speed[i].S - speed[i].F, O_O(i + 1));
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int end = 0;
    for (int i = 0; i < n; i++)
    {
        int dist, limit;
        cin >> dist >> limit;

        for (int i = end + 1; i <= end + dist; i++)
            speed[i].F = limit;

        end += dist;
    }

    end = 0;
    for (int i = 0; i < m; i++)
    {
        int dist, s;

        cin >> dist >> s;

        for (int i = end + 1; i <= end + dist; i++)

            speed[i].S = s;

        end += dist;
    }

    cout << O_O(1) << endl;
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