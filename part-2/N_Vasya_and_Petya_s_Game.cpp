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

bool composite[N + 1];
vector<int> prime;

void linear_sieve(int N)
{
    composite[0] = composite[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (!composite[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] <= N; ++j)
        {
            composite[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    linear_sieve(n);

    vector <int> ans;
    for (int p : prime) {

        int t = p;

        while (t <= n) {
            ans.push_back(t);
            t *= p;
        }
    }

    cout << ans.size() << endl;

    for (auto x : ans) cout << x << " ";
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