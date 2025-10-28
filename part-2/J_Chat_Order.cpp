#include <bits/stdc++.h>

using namespace std;

int N = 2e5 + 2;

vector<string> v;

int main()
{

    int n;

    cin >> n;

    set <string> sum;

    for (int i = 0; i < n; i++)
    {

        string s;

        cin >> s;

        v.push_back(s);
    }

    for (int i = n - 1; i >= 0; i--)
    {

        if (sum.find(v[i]) == sum.end())
        {

            cout << v[i] << endl;

            sum.insert(v[i]);
        }
    }

    return 0;
}
