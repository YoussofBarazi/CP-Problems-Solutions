#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    string pi = "3.145125250562055654025585500212558889632548522244";

    for (int i = 0 ; i < n + 2; i ++)
        cout << pi[i];

    return 0;
}
