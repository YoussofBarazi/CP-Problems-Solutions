#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    string s , t;
    cin >> s >> t;

    int i = 0 , j = 0;

    for (i ; i < s.size() ; i ++)
    {
        if (s[i] == t[j])
            j ++;
        else if (s[i] == '?')
            s[i] = t[j] , j ++;

        if (j == t.size())
        {
            break;
        }
    }

    if (j == t.size())
    {
        for (int i = 0 ; i < s.size() ; i ++)
            if (s[i] == '?') s[i] = 'a';

        cout << "YES" << endl;
        cout << s << endl;
        return ;
    }

    cout << "NO" << endl;
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