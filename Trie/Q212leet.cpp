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
            if (curr->children[idx] == NULL)
                curr->children[idx] = new Node;

            curr = curr->children[idx];
        }

        curr->wordEnd++;
    }
};
class Solution {
public:
    vector<int> dir={{0,1},{1,0},{-1,0},{0,-1}};
    vector<string> helper(vector<vector<char>>& board,Node* node){
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t=new Trie();
        for(int i=0;i<words.size();i++){
            t->insert(words[i]);
        }
        return helper(board,t->root,0,0);
    }
};