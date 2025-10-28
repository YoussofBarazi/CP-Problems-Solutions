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
    string s;
    cin >> s;

    int cnt = 0, n = s.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (st.size())
            st.pop();
        else
            cnt++;
    }

    if (n % 2)
        cout << -1 << endl;
    else if (cnt == st.size())
        cout << cnt << endl;
    else
        cout << max(cnt, (int)st.size()) << endl;
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