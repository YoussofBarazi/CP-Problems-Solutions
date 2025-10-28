#include <iostream>

using namespace std;

bool is_beautiful (int num)
{    
    string s = "";

    while (num)
    {
        s += (num % 2) + '0';
        num /= 2;
    }

    int k = 0;
    while (s[k] == '0')
        k ++;

    int ones = 0;
    
    for (int i = k ; i < s.size() ; i ++)
    {
        if (s[i] == '0')
            return false;
    }

    return s.size() - k == k + 1;
}

int main ()
{
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (is_beautiful(i) && n % i == 0)
        {
            ans = i;
        }
    }

    cout << ans << endl;
}