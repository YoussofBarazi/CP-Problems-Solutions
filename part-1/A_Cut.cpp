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
    int n, k;
    cin >> n >> k;

    deque <int> q;
    for (int i = 0 ; i < n ; i ++) {
        int x; cin >> x;
        q.push_back(x);
    }

    while (k --) {
        q.push_front(q.back());
        q.pop_back();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
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