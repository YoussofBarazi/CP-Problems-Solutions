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


set < string > ans ;
int n ;
string u ;
bool take[N] ;

void BT(string s){

    if(s.size() == n){
        ans.insert(s) ;
        return ;
    }


    for(int i = 0 ; i < n ; i ++){
        if(take[i])continue ;
        take[i] = true ;
        BT(s + u[i]) ;
        take[i] = false ;
    }

}





void solve()
{


    cin >> u ;
    n = u.size() ;

    BT("") ;
















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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}