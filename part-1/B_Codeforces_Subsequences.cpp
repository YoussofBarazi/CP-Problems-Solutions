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
    ll k;
    cin >> k;

    string s = "codeforces";
    vector<int> freq(s.size(), 1);

    ll t = 1;
    while (t < k)
    {
        for (int i = 0; i < s.size(); i++)
        {
            t /= freq[i];

            freq[i]++;

            t *= freq[i];

            if (t >= k)
                break;
        }
    }

    for (int i = 0; i < s.size(); i++)
        cout << string(freq[i], s[i]);
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