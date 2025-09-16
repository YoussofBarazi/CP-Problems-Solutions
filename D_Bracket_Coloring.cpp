#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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
    bool state = s[0] == '(';
    int i = 0, c = 0;
    vector<int> color(n);

    while (i < n)
    {
        while (state && i < n)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (st.size() == 0)
            {
                state = false;
                break;
            }
            else
            {
                color[i] = 1;
                color[st.top()] = 1;
                st.pop();
            }

            i++;
        }

        while (!state && i < n)
        {
            if (s[i] == ')')
                st.push(i);
            else if (st.size() == 0)
            {
                state = true;
                break;
            }
            else
            {
                color[i] = 2;
                color[st.top()] = 2;
                st.pop();
            }
            i++;
        }
    }

    if (st.size() > 0)
    {
        cout << -1 << endl;
        return;
    }

    int k = color[max_element(all(color)) - color.begin()];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == color[i])
            cnt++;
    }

    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
        {
            color[i] = 1;
        }
        k = 1;
    }

    cout << k << endl;

    for (auto x : color)
        cout << x << " ";
    cout << endl;
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