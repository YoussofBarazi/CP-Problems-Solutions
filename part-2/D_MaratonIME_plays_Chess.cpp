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

string chess[8];

bool check(int x, int y, char c1, char c2)
{
    return x < 8 && x >= 0 && y >= 0 && y < 8 && (c1 == chess[x][y] || c2 == chess[x][y]);
}

bool is_captured(int x, int y)
{
    bool captured = false;

    // pawns
    captured |= check(x + 1, y + 1, 'p', '0');
    captured |= check(x + 1, y - 1, 'p', '0');

    // knight
    captured |= check(x + 2, y + 1, 'c', '0');
    captured |= check(x + 2, y - 1, 'c', '0');

    captured |= check(x - 2, y + 1, 'c', '0');
    captured |= check(x - 2, y - 1, 'c', '0');

    captured |= check(x + 1, y + 2, 'c', '0');
    captured |= check(x - 1, y + 2, 'c', '0');

    captured |= check(x + 1, y - 2, 'c', '0');
    captured |= check(x - 1, y - 2, 'c', '0');

    // rook & queen
    // up
    int i = x - 1, j = y;
    while (i >= 0 && chess[i][j] == '.')
        i--;
    captured |= check(i, j, 't', 'r');

    // down
    i = x + 1, j = y;
    while (i < 8 && chess[i][j] == '.')
        i++;
    captured |= check(i, j, 't', 'r');

    // right
    i = x, j = y + 1;
    while (j < 8 && chess[i][j] == '.')
        j++;
    captured |= check(i, j, 't', 'r');

    // left
    i = x, j = y - 1;
    while (j >= 0 && chess[i][j] == '.')
        j--;
    captured |= check(i, j, 't', 'r');

    // bishop & queen
    // up_right
    i = x - 1, j = y + 1;
    while (i >= 0 && j < 8 && chess[i][j] == '.')
        i--, j++;
    captured |= check(i, j, 'b', 'r');

    // up-left
    i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0 && chess[i][j] == '.')
        i--, j--;
    captured |= check(i, j, 'b', 'r');

    // down-right
    i = x + 1, j = y + 1;
    while (i < 8 && j < 8 && chess[i][j] == '.')
        i++, j++;
    captured |= check(i, j, 'b', 'r');

    // down-left
    i = x + 1, j = y - 1;
    while (i < 8 && j >= 0 && chess[i][j] == '.')
        i++, j--;
    captured |= check(i, j, 'b', 'r');

    // king
    captured |= check(x - 1, y + 1, 'k', '0');
    captured |= check(x - 1, y, 'k', '0');
    captured |= check(x - 1, y - 1, 'k', '0');
    captured |= check(x, y + 1, 'k', '0');
    captured |= check(x, y - 1, 'k', '0');
    captured |= check(x + 1, y + 1, 'k', '0');
    captured |= check(x + 1, y, 'k', '0');
    captured |= check(x + 1, y - 1, 'k', '0');

    return captured;
}

void solve()
{

    for (size_t i = 0; i < 8; i++)
    {
        cin >> chess[i];
    }

    string t;
    cin >> t;

    int y = (t[0] - 'a'), x = 8 - (t[1] - '0');

    if (is_captured(x, y))
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
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