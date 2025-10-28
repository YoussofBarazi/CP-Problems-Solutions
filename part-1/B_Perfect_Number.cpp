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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int cnt = 0, k, ans = 0;;

void O_O(int s, ll num) {
    
    if (s == 0) {
        cnt ++;

        if (cnt == k && ans == 0) {
            ans = num;
        }

        return ;
    }

    O_O (s, num * 10);

    for (int d = 1 ; d < 10 ; d ++) {
        if (s >= d) {
            O_O(s - d, num * 10 + d);
        }
    }
}

void solve()
{
    cin >> k;

    O_O(10, 0);

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