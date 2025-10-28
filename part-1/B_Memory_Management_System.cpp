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



void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector <int> memory(m + 2, 0);

    for (int i = 0 ; i < n ; i ++) {
        int l, r;
        cin >> l >> r;

        memory[l] ++;
        memory[r + 1] --;
    }

    int s = 0;
    vector <int> s_r(m + 1, 0);

    for (int i = 1 ; i <= m ; i ++) {
        memory[i] += memory[i - 1];
        
        if (memory[i] == 0) {
            s ++;
        } else {

            if (s > 0) {
                s_r[s] = max(i - 1, s_r[s]);
            }

            s = 0;
        }
    }

    if (s > 0) {
        s_r[s] = m;
    }

    for (int i = m ; i >= 1 ; i --) {
        s_r[i - 1] = max(s_r[i - 1], s_r[i]);        
    }

    while(q --) {
        int k;
        cin >> k;

        if (s_r[k] == 0) {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }
        cout << s_r[k] - k + 1 << " " << s_r[k] << endl;
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