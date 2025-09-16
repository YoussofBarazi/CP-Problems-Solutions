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

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    map<int, int> parentA, parentB;
    map<string, int> v;
    vector<pair<string, string>> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].F >> s[i].S;

        v[s[i].F] = 0;
        v[s[i].S] = 0;
    }

    int cnt = 1;
    for (auto &x : v)
        x.S = cnt++;

    int A = v[a], B = v[b];

    bool stay = true;
    while (stay)
    {
        stay = false;
        for (int i = 0; i < n; i++)
        {
            if (A == v[s[i].S])
            {
                parentA[A] = v[s[i].F];
                A = v[s[i].F];
                stay = true;
                break;
            }
        }
    }

    stay = true;
    while (stay)
    {
        stay = false;
        for (int i = 0; i < n; i++)
        {
            if (B == v[s[i].S])
            {
                parentB[B] = v[s[i].F];
                B = v[s[i].F];
                stay = true;
                break;
            }
        }
    }

    A = v[a], B = v[b];

    if (parentA[A] == parentB[B])
    {
        cout << "SIBLINGS" << endl;
        return;
    }

    bool ok = false;
    cnt = 0;

    while (parentA[A])
    {
        if (parentA[A] == B)
        {
            ok = true;
            break;
        }
        cnt++;
        A = parentA[A];
    }

    if (ok)
    {
        cout << b << " is the ";

        while (cnt > 1)
        {
            cout << "great-";
            cnt--;
        }
        if (cnt > 0)
            cout << "grand-";
        cout << "mother of " << a << endl;
        return;
    }

    cnt = 0;
    A = v[a], B = v[b];

    while (parentB[B])
    {
        if (parentB[B] == A)
        {
            ok = true;
            break;
        }
        cnt++;
        B = parentB[B];
    }

    if (ok)
    {
        cout << a << " is the ";

        while (cnt > 1)
        {
            cout << "great-";
            cnt--;
        }
        if (cnt > 0)
            cout << "grand-";
        cout << "mother of " << b << endl;
        return;
    }

    vector<int> firstSharedParent(209, 0);
    int cnt1 = 0, cnt2 = 0;
    A = v[a], B = v[b];

    while (parentA[A])
    {
        firstSharedParent[parentA[A]]++;
        A = parentA[A];
    }

    while (parentB[B])
    {
        cnt2++;
        if (firstSharedParent[parentB[B]])
        {
            ok = true;
            break;
        }
        B = parentB[B];
    }

    int p = parentB[B];
    A = v[a];

    while (parentA[A])
    {
        cnt1++;
        if (parentA[A] == p)
            break;
        A = parentA[A];
    }

    cnt = abs(cnt1 - cnt2);

    if (ok && min(cnt1, cnt2) == 1)
    {
        if (cnt1 > cnt2)
            cout << b;
        else
            cout << a;

        cout << " is the ";

        while (cnt > 1)
        {
            cout << "great-";
            cnt--;
        }

        cout << "aunt of ";

        if (cnt1 > cnt2)
            cout << a;
        else
            cout << b;
        cout << endl;

        return;
    }

    if (ok)
    {
        cout << "COUSINS" << endl;
        return;
    }

    cout << "NOT RELATED" << endl;
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