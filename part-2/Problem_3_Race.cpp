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

void solve()
{
    int k, n;
    cin >> k >> n;

    while (n--)
    {
        ll x;
        cin >> x;

        ll speed = 1, dist = 0, time = 0;

        while (dist < k)
        {
            dist += speed;
            time++;

            if (dist >= k)
                break;

            if (speed >= x)
                dist += speed, time++;

            speed++;
        }

        cout << time << endl;
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