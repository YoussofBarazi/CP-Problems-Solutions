#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define x first
#define y second
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
    pair<int, int> alice, bob;
    cin >> alice.x >> alice.y >> bob.x >> bob.y;

    double dist = sqrt((alice.x - bob.x) * (alice.x - bob.x) + (alice.y - bob.y) * (alice.y - bob.y));

    int E;
    cin >> E;

    while (E--)
    {
        pair<int, int> eve;
        cin >> eve.x >> eve.y;

        double dist1 = sqrt((eve.x - bob.x) * (eve.x - bob.x) + (eve.y - bob.y) * (eve.y - bob.y));
        double dist2 = sqrt((alice.x - eve.x) * (alice.x - eve.x) + (alice.y - eve.y) * (alice.y - eve.y));

        double dif = abs(dist - dist1 - dist2);
        if (dif < 1e-10)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}