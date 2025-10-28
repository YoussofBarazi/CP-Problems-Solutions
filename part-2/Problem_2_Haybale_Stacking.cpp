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
    int n, k;
    cin >> n >> k;

    vector<int> stacks(n + 2, 0);

    while (k--)
    {
        int a, b;
        cin >> a >> b;

        stacks[a]++, stacks[b + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        stacks[i] += stacks[i - 1];
    }

    sort(all(stacks));

    cout << stacks[(n + 1) / 2] << endl;
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