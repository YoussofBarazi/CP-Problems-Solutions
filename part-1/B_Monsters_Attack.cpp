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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    ll hits = 0, dist = 0;
    int left = -1, right = n;

    for (int i = 0; i < n; i++)
    {
        if (x[i] < 0)
            left = i;
        else
            right = min(i, right);
    }

    while (true)
    {
        if (left <= -1 && right >= n)
            break;

        if (left > -1 && right < n)
        {
            if (x[left] + dist >= 0)
            {
                if (hits < a[left])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[left --];
                continue;
            }
            if (x[right] - dist <= 0)
            {
                if (hits < a[right])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[right ++];
                continue;
            }

            if (abs(x[left] + dist) < x[right] - dist)
            {
                hits += k * abs(x[left] + dist);
                dist += abs(x[left] + dist);

                if (hits < a[left])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[left];
                left--;
            }
            else
            {
                hits += k * (x[right] - dist);
                dist += x[right] - dist;

                if (hits < a[right])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[right];

                right++;
            }
        }
        else if (left > -1)
        {
            if (x[left] + dist >= 0)
            {
                if (hits < a[left])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[left --];
                continue;
            }

            hits += k * abs(x[left] + dist);
            dist += abs(x[left] + dist);

            if (hits < a[left])
            {
                cout << "NO" << endl;
                return;
            }

            hits -= a[left];

            left--;
        }
        else
        {
            if (x[right] - dist <= 0)
            {
                if (hits < a[right])
                {
                    cout << "NO" << endl;
                    return;
                }

                hits -= a[right ++];
                continue;
            }
            
            hits += k * (x[right] - dist);
            dist += x[right] - dist;

            if (hits < a[right])
            {
                cout << "NO" << endl;
                return;
            }

            hits -= a[right];

            right++;
        }
       // cout << left << " " << right << " " << dist << " " << hits << endl;
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