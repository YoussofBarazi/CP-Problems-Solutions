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
    int n;
    cin >> n;

    map <string, priority_queue<int, vector<int>, greater<int>>> m;

    for (int i = 0 ; i < n ; i ++) {
        string s; int x;
        cin >> s >> x;

        m[s].push(x);
    }

    while(m.size()) {
        vector <string> del;
        for (auto& [s, q] : m) {
            cout << s << " " << q.top() << endl;
            q.pop();
            if (q.empty()) del.push_back(s);
        }

        for (auto s : del) {
            m.erase(s);
        }
    }
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