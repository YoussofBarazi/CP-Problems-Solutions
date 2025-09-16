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
    string s, t;
    cin >> s >> t;

    vector <vector<int>> freq1(26) , freq2(26);

    for (int i = 0 ; i < s.size() ; i ++)
        freq1[s[i] - 'a'].push_back(i);
    for (int i = 0 ; i < s.size() ; i ++)
        freq2[t[i] - 'a'].push_back(i);

    for (int c = 0 ; c < 26 ; c ++)
    {
        vector <int> f(26 , 0);

        for (auto ndx : freq2[c])
        {
            f[s[ndx] - 'a'] ++;
        }

        int cnt = 0;

        for (int i = 0 ; i < 26 ; i ++)
        {   
            if (f[i] == 0)
                continue;

            if (f[i] == int(freq1[i].size()))
            {   
                cnt ++; 
                continue;
            }
            cout << "NO" << endl;
            return ;
        }

        if (cnt > 1)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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