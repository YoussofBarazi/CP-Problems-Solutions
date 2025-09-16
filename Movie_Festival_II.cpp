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
 
struct Event
{
    int start , ended , id;
 
    bool operator<(Event e)
    {
        return start < e.start;
    }
};
 
void solve()
{
    int n , k;
    cin >> n >> k;
    
    vector <pair<int , int>> event;
    
    for (int i = 0 ; i < n ; i ++)
    {
        int s , e;
        cin >> s >> e;
 
        event.pb({e , s});
    }
 
    sort(all(event));
 
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> endAt;
 
    for (auto e : event)
    {
        if (!endAt.empty() && endAt.top() <= e.S)
            endAt.pop();
 
        if (endAt.size() < k)
            endAt.push(e.F) , ans ++;
    }
 
    cout << ans << endl;
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