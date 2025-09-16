#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
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

    ll ans = 0;
    set<int> A, B, C;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'B')
            B.insert(i);
        else if (s[i] == 'A')
            A.insert(i);
        else
            C.insert(i);

    auto x = C.begin();
    auto y = A.rbegin();

    while (C.size() && A.size() && *x < *y)
    {
        A.insert(*x);
        C.insert(*y);

        swap(s[*x] , s[*y]);

        A.erase(A.find(*y));
        C.erase(C.find(*x));

        x = C.begin();
        y = A.rbegin();
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (C.size() && B.size() && A.size())
        {
            auto a = A.begin();
            auto b = B.rbegin();
            auto c = C.rbegin();

            while (B.size() && *b > *c)
            {
                B.erase(B.find(*b));
                b = B.rbegin();
            }

            if (B.size() && *c > *b && *b > *a)
                ans++, C.erase(C.find(*c)), B.erase(B.find(*b)), A.erase(A.find(*a));
        }
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}