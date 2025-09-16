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

int b[3][3][3][3];
int res[3][3];

int row(int i, int j, int k) {
    int cnt1 = 0, cnt2 = 0;
    for (int h = 0 ; h < 3 ; h ++) {
        cnt1 += b[i][j][k][h] == 1;
        cnt2 += b[i][j][k][h] == 2;
    }

    if (cnt1 == 3) return 1;
    else if (cnt2 == 3) return 2;
    else return 0;
}

int col(int i, int j, int h) {
    int cnt1 = 0, cnt2 = 0;
    for (int k = 0 ; k < 3 ; k ++) {
        cnt1 += b[i][j][k][h] == 1;
        cnt2 += b[i][j][k][h] == 2;
    }

    if (cnt1 == 3) return 1;
    else if (cnt2 == 3) return 2;
    else return 0;
}

int winner(int i, int j) {
    if (res[i][j]) {
        return res[i][j];
    }   

    int cnt1 = 0;
    int cnt2 = 0;

    for (int k = 0 ; k < 3 ; k ++) {
        cnt1 += b[i][j][k][k] == 1;
        cnt2 += b[i][j][k][k] == 2;
    }

    if (cnt1 == 3) return res[i][j] = 1;
    else if (cnt2 == 3) return res[i][j] = 2;

    cnt1 = 0, cnt2 = 0;

    for (int k = 0, h = 2 ; k < 3 ; k ++, h --) {
        cnt1 += b[i][j][k][h] == 1;
        cnt2 += b[i][j][k][h] == 2;
    }

    if (cnt1 == 3) return res[i][j] = 1;
    else if (cnt2 == 3) return res[i][j] = 2;

    for (int t = 0 ; t < 3 ; t ++) {
        if (row(i, j, t)) {
            return res[i][j] = row(i, j, t);
        } else if (col (i, j, t)) {
            return res[i][j] = col(i, j, t);
        }
    }

    return res[i][j] = 0;
}

map <string, pair<int,int>> pos;

void find_empty(int t, string& s1 , string& s2) {
    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++) {
            for (int k = 0 ; k < 3 ; k ++) {
                for (int h = 0 ; h < 3 ; h ++) {
                    if (!b[i][j][k][h]) {
                        b[i][j][k][h] = t;
                        for (auto x : pos) {
                            if (x.S == make_pair(i, j)) s1 = x.F;
                            if (x.S == make_pair(k, h)) s2 = x.F;
                        }
                        return ;
                    }
                }
            }
        }
    }
}

void solve()
{
    // freopen("tictactoe.in", "r", stdin);
    int n;
    cin >> n;

    pos["TL"] = {0, 0};
    pos["TM"] = {0, 1};
    pos["TR"] = {0, 2};
    pos["ML"] = {1, 0};
    pos["M"] =  {1, 1};
    pos["MR"] = {1, 2};
    pos["BL"] = {2, 0};
    pos["BM"] = {2, 1};
    pos["BR"] = {2, 2};

    bool ok = true;
    string last = "nothing";
    string invalid;

    vector <pair<string, string>> q(n + 1);
    for (int i = 1 ; i <= n ; i ++) {
        string s1, s2;
        cin >> s1 >> s2;
        q[i] = {s1, s2};
    }

    for (int t = 1 ; t <= n ; t ++) {
        string s1 = q[t].F, s2 = q[t].S;
        int i = pos[s1].F, j = pos[s1].S, k = pos[s2].F, h = pos[s2].S;

        if (res[i][j]) {
            bool ok = false;
            if (b[i][j][k][h]) {
                for(int kk = 0 ; kk < 3 ; kk ++) {
                    for (int hh = 0 ; hh < 3 ; hh ++) {
                        if (!b[i][j][kk][hh]) {
                            ok = true;
                            h = hh;
                            k = kk;
                            b[i][j][k][h] = (t % 2) ? 1 : 2;

                            for (auto x : pos) {
                                if (x.S == make_pair(k, h)) s2 = x.F;
                            }
                        }
                    }
                }

                if (!ok) {
                    find_empty(t % 2 ? 1 : 2, s1, s2);
                } 
            }
        } if (last == "nothing") {

        } else if (last != s1) {
            ok = false;
            invalid = s1 + ' ' + s2;
        }
        
        last = s2;
        
        i = pos[s1].F, j = pos[s1].S, k = pos[s2].F, h = pos[s2].S;
        b[i][j][k][h] = (t % 2) ? 1 : 2;
        winner(i, j);
    }

    if (!ok) {
        cout << "INVALID " << invalid << endl;
        return ;
    }

    for (int i = 0 ; i < 3 ; i ++) {
        for (int j = 0 ; j < 3 ; j ++) {
            int w = winner(i, j);

            if (w == 0) {
                cout << 'E';
            } else if (w == 1) {
                cout << 'X';
            } else {
                cout << 'O';
            }

            if (j != 2) {
                cout << '|';
            }
        }
        if (i != 2) {
            cout << endl << "-----" << endl;
        }
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