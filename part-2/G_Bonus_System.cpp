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
    int n;
    string pw;
    cin >> n >> pw;

    vector<string> s(n);
    vector<int> score(n, 0);
    for (auto &x : s)
        cin >> x;

    priority_queue<pii> q;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;

        if (t == "bonus")
        {
            int id, b;
            string p;
            cin >> id >> b >> p;

            if (p == pw)
                cout << "Updated successfully\n---" << endl;
            else
            {
                cout << "Wrong password please try again\n---" << endl;
                continue;
            }

            score[id - 1] += b;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (score[i] > 0)
                    q.push({score[i], i});
            }

            int rank = 0;
            vector<int> tied;

            while (q.size())
            {
                pii t = q.top();

                if (tied.size() == 0 || score[tied.back()] == score[t.second])
                {
                    if (tied.size() == 0 || tied.back() != t.second)
                        tied.push_back(t.second);
                    q.pop();
                }
                else
                {
                    rank++;

                    sort(all(tied));

                    for (auto id : tied)
                    {
                        cout << rank << " " << id + 1 << " " << s[id] << " " << score[id] << endl;
                    }

                    tied.clear();

                    tied.push_back(t.second);
                }
            }
            rank++;
            
            if (tied.size()) sort(all(tied));
            for (auto id : tied)
            {
                cout << rank << " " << id + 1 << " " << s[id] << " " << score[id] << endl;
            }

            cout << "---\n";
        }
    }
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