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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector <string> ans;
    priority_queue<string, vector<string>, greater<string>> q;
    
    while (s != t) {
        for (int i = 0 ; i < n ; i ++)  {
            if (s[i] != t[i]) {
                swap(s[i], t[i]);
                q.push(s);
                swap(s[i], t[i]);
            }
        }

        s = q.top();
        ans.push_back(s);
        q = {};
    }

    cout << ans.size() << endl;
    for (auto &x : ans) {
        cout << x << endl;
    }
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