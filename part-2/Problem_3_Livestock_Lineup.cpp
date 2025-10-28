#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector<string> lineup = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<vector<string>> permutations;
bool taken[8];

void generate(vector<string> p = {})
{
    if (p.size() == 8)
    {
        permutations.pb(p);
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (!taken[i])
        {
            p.pb(lineup[i]);
            taken[i] = true;
            generate(p);
            taken[i] = false;
            p.pop_back();
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<string, string>> constraint(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> constraint[i].F >> s >> s >> s >> s >> constraint[i].S;
    }

    generate();

    vector<string> ans = lineup;
    for (int i = 0; i < permutations.size(); i++)
    {
        bool ok = true;
        ans = permutations[i];

        for (int j = 0; j < n; j++)

            for (int k = 0; k < permutations[i].size(); k++)

                if (constraint[j].F == permutations[i][k])

                    ok &= (k > 0 && permutations[i][k - 1] == constraint[j].S) || (k + 1 < 8 && permutations[i][k + 1] == constraint[j].S);

        if (ok)
            break;
    }

    for (auto x : ans)
        cout << x << endl;
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