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
    int n;
    string s;
    cin >> n >> s;

    stack<int> st;
    int ind = -1;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (st.size())
            st.pop();
        else
            ind = i, cnt++;
    }

    string ans = "Yes";

    if (st.size() == 0 && ind != -1)
        ans = "No";
    else if (st.size() == 1 && ind == -1)
        ans = "No";
    else if (st.size() > 1)
        ans = "No";
    else if (cnt > 1)
        ans = "No";

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