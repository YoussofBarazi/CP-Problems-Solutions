#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int passes_to[N] , recived[N] , a[N];

int main()
{
    freopen("hoofball.in" , "r" , stdin);
    freopen("hoofball.out" , "w" , stdout);

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }

    sort(a , a + n);

    passes_to[0] = 1;
    
    if (n > 1)
        passes_to[n - 1] = n - 2;

    recived[1] = 1;

    if (n > 1)
        recived[n - 2] = 1;

    for (int i = 1 ; i < n - 1 ; i ++)
    {
        if (a[i] - a[i - 1] <= a[i + 1] - a[i])
        {
            passes_to[i] = i - 1;
            recived[i - 1] ++;
        }
        else 
        {
            passes_to[i] = i + 1;
            recived[i + 1] ++;
        }
    }

    int cnt = 0;

    for (int i = 1 ; i < n ; i ++)
    {
        if (recived[i - 1] == 1 && passes_to[i - 1] == i && recived[i] == 1 && passes_to[i] == i - 1)
        {
            cnt ++;
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        if (recived[i] == 0)
            cnt ++;
    }

    cout << cnt << endl;
}