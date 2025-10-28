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
    int x , n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    while (n --)
    {
        int x;
        cin >> x;

        q.push(x);
    }
    
    ll ans = 0;

    while (q.size() > 1)
    {
        int x = q.top();
        q.pop();

        x += q.top();
        q.pop();

        q.push(x);

        ans += x; 
    }

    cout << ans << endl;
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