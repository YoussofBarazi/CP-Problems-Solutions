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

const int N = 1009;

vector <int> interact(vector <int> f)
{
    cout << "next ";
    for (int i : f)
        cout << i << " ";
    cout << endl;

    int n;
    cin >> n;

    vector <int> group(10);

    for (int i = 0 ; i < n ; i ++)
    {
        string t;
        cin >> t;

        for (auto c : t)
            group[c - '0'] = i;
    }

    return group;
}

void solve()
{
    interact({0 , 1});
    vector <int> group = interact({1});
    
    while (group[0] != group[1])
    {
        interact({0 , 1});
        group = interact({1});
    }

    while (group[2] != group[1])
    {
        group = interact({0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9});
    }

    cout << "done" << endl;
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