#include <iostream>
#include <vector>
using namespace std;

bool canPlaceH(vector<vector<char>> &board, int r, int c, string word)
{
    if (word.length() > board[0].size())
        return false;
    else if (word.length() <= board[0].size())
    {
        if (c == 0 && c + word.length() < board[0].size())
        {
            if (board[r][c + word.length()] != '+')
            {
                return false;
            }
        }
        if (c == (board[0].size() - word.length()) && board[r][c - 1] != '+')
        {
            return false;
        }
        if (c != 0 && c + word.length() <= (board[0].size()) && (board[r][c - 1] != '+' || board[r][c + word.length()] != '+'))
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}
vector<bool> placeH(vector<vector<char>> &board, int r, int c, string word)
{
    vector<bool> loc(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r][c + i] == '-')
        {
            loc[i] = true;
            board[r][c + i] = word[i];
        }
    }
    return loc;
}
void unplaceH(vector<vector<char>> &board, int r, int c, vector<bool> &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[r][c + i] = '-';
        }
    }
}
bool canPlaceV(vector<vector<char>> &board, int r, int c, string word)
{
    if (word.length() > board.size())
        return false;
    else if (word.length() <= board.size())
    {
        if (r == 0 && r + word.length() < board.size())
        {
            if (board[r + word.length()][c] != '+')
            {
                return false;
            }
        }
        if (r == (board.size() - word.length()) && board[r - 1][c] != '+')
        {
            return false;
        }
        if (r != 0 && r + word.length() <= (board.size()) && (board[r - 1][c] != '+' || board[r + word.length()][c] != '+'))
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

vector<bool> placeV(vector<vector<char>> &board, int r, int c, string word)
{
    vector<bool> loc(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r + i][c] == '-')
        {
            loc[i] = true;
            board[r + i][c] = word[i];
        }
    }
    return loc;
}

void unplaceV(vector<vector<char>> &board, int r, int c, vector<bool> &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[r + i][c] = '-';
        }
    }
}
int crossWord_(vector<vector<char>> &board, vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (vector<char> row : board)
        {
            for (char ch : row)
            {
                cout << ch << " ";
            }
            cout << endl;
        }
        return 1;
    }

    int count = 0;
    string word = words[idx];
    vector<bool> loc(word.length(), false);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == word[0])
            {
                if (canPlaceH(board, i, j, word))
                {
                    loc = placeH(board, i, j, word);
                    count += crossWord_(board, words, idx + 1);
                    unplaceH(board, i, j, loc);
                }
                if (canPlaceV(board, i, j, word))
                {
                    loc = placeV(board, i, j, word);
                    count += crossWord_(board, words, idx + 1);
                    unplaceV(board, i, j, loc);
                }
            }
        }
    }
    return count;
}

void crossWord()
{
    vector<vector<char>> board = {
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossWord_(board, words, 0) << endl;
}
int main()
{
    crossWord();
    return 0;
}
