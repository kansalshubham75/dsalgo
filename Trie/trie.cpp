#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int wordEnd;
    vector<Node *> children;
    Node()
    {
        this->children.assign(26, nullptr);
        this->wordEnd = 0;
    }
};
//leetcode 208
class Trie
{
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = (int)(word[i] - 'a');
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new Node;

            curr = curr->children[idx];
        }

        curr->wordEnd++;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = (int)(word[i] - 'a');
            if (curr == nullptr)
                return false;

            curr = curr->children[idx];
        }

        return curr->wordEnd > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = (int)(word[i] - 'a');
            if (curr == nullptr)
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};

//leetcode 211
class WordDictionary {
public:
    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = (int)(word[i] - 'a');
            if (curr->children[idx] == NULL)
                curr->children[idx] = new Node;

            curr = curr->children[idx];
        }

        curr->wordEnd++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
    }
};



int main()
{
    return 0;
}