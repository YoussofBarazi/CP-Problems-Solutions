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

struct TrieNode
{
    TrieNode *childNode[2];
    int wordCount;

    TrieNode()
    {
        wordCount = 0;
        for (int i = 0; i < 2; i++)
            childNode[i] = NULL;
    }
};

void insert_key(TrieNode *root, string key)
{
    TrieNode *currentNode = root;

    for (int i = 31; i >= 0; i--)
    {
        int ind = key[i] - '0';
        if (currentNode->childNode[ind] == NULL)
        {
            TrieNode *newNode = new TrieNode();

            currentNode->childNode[ind] = newNode;
        }

        currentNode = currentNode->childNode[ind];
    }

    currentNode->wordCount++;
}

int get_ans(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (currentNode->childNode[(key[i] - '0' + 1) % 2] == NULL)
        {
            currentNode = currentNode->childNode[key[i] - '0'];
            continue;
        }

        ans += 1 << i;
        currentNode = currentNode->childNode[(key[i] - '0' + 1) % 2];
    }

    return ans;
}

bool delete_key(TrieNode *root, string &word)
{
    TrieNode *currentNode = root;
    TrieNode *lastBranchNode = NULL;
    char lastBrachChar;

    for (int i = 31; i >= 0; i--)
    {
        int ind = word[i] - '0';

        if (currentNode->childNode[ind] == NULL)
            return false;

        int count = 0;
        for (int i = 0; i < 2; i++)
            if (currentNode->childNode[i] != NULL)
                count++;

        if (count > 1)
        {
            lastBranchNode = currentNode;
            lastBrachChar = word[i];
        }
        currentNode = currentNode->childNode[ind];
    }

    int count = 0;
    for (int i = 0; i < 2; i++)
        if (currentNode->childNode[i] == NULL)
            count++;

    if (count < 2)
    {
        currentNode->wordCount--;
        return true;
    }

    if (lastBranchNode != NULL)
    {
        lastBranchNode->childNode[lastBrachChar - '0'] = NULL;
        return true;
    }
    else
    {
        root->childNode[word[31] - '0'] = NULL;
        return true;
    }
}

int main()
{
    // IOS;

    int t = 1;
    cin >> t;

    TrieNode *root = new TrieNode();
    map<int, int> freq;
    insert_key(root, string(32, '0'));

    while (t--)
    {
        char p;
        int x;
        cin >> p >> x;

        string bit(32, '0');
        for (int i = 31; i >= 0; i--)
            if (x & (1 << i))
                bit[i] = '1';

        if (p == '+')
        {
            insert_key(root, bit);
            freq[x]++;
        }
        else if (p == '-')
        {
            freq[x]--;

            if (freq[x] == 0)
                delete_key(root, bit);
        }
        else
        {
            cout << get_ans(root, bit) << endl;
        }
    }

    return 0;
}