/*
SkibidiDomDomDomDomDomDo&######&mDomDomDomDomDomDo
YesYesYesYesYesYesYes@#BGGBBBBBB#@@YesYesYesYesYes
@@@@@@@@@@@@@@@@@@@@@#?JJ?7?7?JJG@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@BJ5YJ!!7?JJ5@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@BYYJY??YJJJYB@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@#YJYY??J?7?5&@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@#YJ55JYYYJJG@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@&P5JJJ??JYP&@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@&&BBGPBBBBGG5YYPGB#@@@@@@@@@@@@@@
@@@@@@@@@@@@@&#BGGPPP5P55555YYYYPPPPGB#&@@@@@@@@@@
@@@@@@@@@@@#GPPPPPPPPPGPPPPPP55PPPPPPPPGB&@@@@@@@@
@@@@@@@@@&GPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPGB&@@@@@@
@@@@@@@@#PPPPPPPPPPPPPPPPPPPP5PPPY5PPPPPPPPPG&@@@@
@@@@@@@BPPGGPPPPPPPPPP5PPPPPPPPPPJ?YY5PGPPPP5P&@@@
@@@@@&GPGGGGPPPPPPPPPPP5PPP5PGGGGPJ??JJY5PPPPPPB@@
@@@@#GGGGGBGPPPPPPPPPPP5PGPPGGP5PY?JJJ???JY5PP55G@
@@@#GGGGGBBGGPPPPPPPPPPP5GPGGJJ??JJJJJ?????JYY555G
@@&P55PGGB#BGGGPPPPPPPPGPYGBBPP5JJ??Y555YJJYYYYYP#
@@G5YYJY5B&#BBGGPPPPPPPY7~?PBBBBGPPGB#&BP5YYYYYYP@
@#555YYJY&&BBGGGPPPPPPPY!~^YBGGGGGGBBB#&BP5YY555#@
@BYYYYY5#&BBBGGGPPPPPPPP5Y5PGGGGGPPPGGB##BGPGGB#@@
@GJYYYG&@BGGBBGGPPPPPPPPPPPPPPPPPPPPPPGGGBGP&@@@@@
&PJJYY#@#GGGGBGGGGPGPPPPPPPPPPPPPPPPPPPPPPP5#@@@@@
B5YJ5YB@BGGBGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP5B@@@@@
#G55G&@@BGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP5B@@@@@
@&B#@@@@#GGGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP#@@@@
@@@@@@@#GGGGGGGGGGGGGGGGGGPGGPPPPPPPPPPPGGP5JY&@@@
@@@@@@&GGGBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5?!!!G@@@
@@@@@@&YY5PBBBBBGGGGGGGGGGGGGGGGGGGGGPYJ7!!!!!5@@@
@@@@@@#J?7?JY5PGBBBBBBBBBBBBBGGGP5Y?7!!!!!!!!!?&@@
@@@@@@&J??77777?JY55PGPP55YYJ??77!!!!!!!!!!!!!7&@@
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define Endl endl
#define ll long long
#define in insert
#define F first
#define S second
#define ii pair <int, int> 
#define vii vector <ii>
#define loop(i, n) for(int i = 0 ; i < n ; i++)
#define lop(i, x, n) for(int i = x ; i <= n ; i++)
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const int N = 1e4 + 5;
int n, k;
vector <vector<int>> adj(N);
vector <int> vis;

int bfs (int x) {
    queue <int> q;
    vector <int> dis (n+1);
    vis.assign(n+1, 0);
    int cnt = 1;

    vis[x] = 1;
    dis[x] = 0;
    q.push(x);

    int s;
    while (!q.empty()) {
        s = q.front(); q.pop();

        for (auto u : adj[s]) {
            if (vis[u]) continue;
            if (cnt == k) break;

            cnt++;

            vis[u] = 1;

            dis[u] = dis[s] + 1;

            q.push(u);
        }
    }

    return s;
}

ii bfs2 (int x) {
    queue <int> q;
    vector <int> vis2 (n+1), dis (n+1);
    int cnt = 1;

    vis2[x] = 1;
    dis[x] = 0;
    q.push(x);

    int s;
    while (!q.empty()) {
        s = q.front(); q.pop();

        for (auto u : adj[s]) {
            if (vis2[u] || !vis[u]) continue;

            cnt++;

            vis2[u] = 1;

            dis[u] = dis[s] + 1;

            q.push(u);
        }
    }

    return {s, dis[s]};
}

void solve() {
    scanf("%d%d", &n, &k);

    loop (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);

        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (k == 1) {
        printf("1");
        return;
    }
    int mn = 1e9;
    
    lop (i, 1, n) {
        int t1 = bfs(i);
        ii t2 = bfs2(t1);

        //cout<<i<<" "<<t1<<" "<<t2.F<<" "<<t2.S<<Endl;
        mn = min(mn, t2.S + 1);
    }

    printf("%d", mn);
}

int main() {
    
    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}