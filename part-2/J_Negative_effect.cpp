/*
أحلى كوووتش...تفضاااال
            .------.____
         .-'       \ ___)
      .-'         \\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\
        \ /    /__v__\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|
                      (
                        )     (
                 ___...(-------)-....___
             .-""       )    (          ""-.
       .-'``'|-._             )         _.-|
      /  .--.|   `""---...........---""`   |
     /  /    |                             |
     |  |    |                             |
      \  \   |                             |
       `\ `\ |                             |
         `\ `|                             |
         _/ /\                             /
        (__/  \                           /
     _..---""` \                         /`""---.._
  .-'           \                       /          '-.
 :               `-.__             __.-'              :
 :                  ) ""---...---"" (                 :
  '._               `"--...___...--"`              _.'
    \""--..__                              __..--""/
     '._     """----.....______.....----"""     _.'
        `""--..,,_____            _____,,..--""`
                      `"""----"""`
*/
#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
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

struct node
{
    ll seg, pref, suf, sum;
};

ll a[N];
node st[4 * N];

void merge(int vertix, int left, int right)
{
    node &p = st[vertix], l = st[left], r = st[right];

    p.seg = max({l.seg, r.seg, l.suf + r.pref});
    p.pref = max({l.pref, l.sum + r.pref});
    p.suf = max(r.suf, r.sum + l.suf);
    p.sum = r.sum + l.sum;
}

void build(int vertix, int left, int right)
{
    if (left == right) // base case : single element in the segment
    {
        st[vertix] = {a[left], a[left], a[left], a[left]};
        return;
    }

    int mid = left + (right - left) / 2; // deviding the segment

    build(vertix * 2, left, mid);          // left segment
    build(vertix * 2 + 1, mid + 1, right); // right segment

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

void update(int vertix, int left, int right, int ndx, int value)
{
    if (left == right) // base case : single element in the segment
    {
        st[vertix] = {value, value, value, value};
        return;
    }

    int mid = left + (right - left) / 2; // deviding the segment

    if (ndx <= mid)
        update(vertix * 2, left, mid, ndx, value); // left segment
    else
        update(vertix * 2 + 1, mid + 1, right, ndx, value); // right segment

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        ll tmp = a[i];

        update(1, 1, n, i, m);

        cout << st[1].seg << " ";

        update(1, 1, n, i, tmp);
    }
    cout << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}