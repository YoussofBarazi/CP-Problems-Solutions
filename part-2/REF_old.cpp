#include <bits/stdc++.h>

using namespace std;

// Trie code

struct TrieNode
{
    TrieNode *childNode[26];
    int wordCount;

    TrieNode()
    {
        wordCount = 0;
        for (int i = 0; i < 26; i++)
            childNode[i] = NULL;
    }
};

void insert_key(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    for (auto c : key)
    {
        if (currentNode->childNode[c - 'a'] == NULL)
        {
            TrieNode *newNode = new TrieNode();

            currentNode->childNode[c - 'a'] = newNode;
        }

        currentNode = currentNode->childNode[c - 'a'];
    }

    currentNode->wordCount++;
}

bool search_key(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    for (auto c : key)
    {
        if (currentNode->childNode[c - 'a'] == NULL)
            return false;

        currentNode = currentNode->childNode[c - 'a'];
    }

    return (currentNode->wordCount > 0);
}

bool isPrefixExist(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;

    for (auto c : key)
    {

        if (currentNode->childNode[c - 'a'] == NULL)
            return false;

        currentNode = currentNode->childNode[c - 'a'];
    }

    return true;
}

bool delete_key(TrieNode *root, string &word)
{
    TrieNode *currentNode = root;
    TrieNode *lastBranchNode = NULL;
    char lastBrachChar = 'a';

    for (auto c : word)
    {
        if (currentNode->childNode[c - 'a'] == NULL)
            return false;
        else
        {
            int count = 0;
            for (int i = 0; i < 26; i++)
                if (currentNode->childNode[i] != NULL)
                    count++;

            if (count > 1)
            {
                lastBranchNode = currentNode;
                lastBrachChar = c;
            }
            currentNode = currentNode->childNode[c - 'a'];
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
        if (currentNode->childNode[i] != NULL)
            count++;

    if (count > 0)
    {
        currentNode->wordCount--;
        return true;
    }

    if (lastBranchNode != NULL)
    {
        lastBranchNode->childNode[lastBrachChar - 'a'] = NULL;
        return true;
    }
    else
    {
        root->childNode[word[0] - 'a'] = NULL;
        return true;
    }
}
