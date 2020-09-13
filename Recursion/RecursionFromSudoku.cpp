#include<iostream>
#include<vector>
using namespace std;
vector<int> row(9,0);
vector<int> col(9,0);
vector<vector<int>> mat(3,vector<int>(3,0));
void sudoku_initialize(vector<vector<int>> &board){
    int mask=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!=0){
                mask=(1<<board[i][j]);
                row[i] |= mask;
                col[j] |= mask;
                mat[i/3][j/3] |= mask;
            }
        }
    }
}

int fill_sudoku(vector<vector<int>> &board,int bno){
    if(bno==81){
        return 1;
    }
    int count=0;
     int r= bno/9;
     int c= bno%9;
    if(board[r][c]!=0) {  
            
    for(int i=0;i<9;i++){
        int mask=(1<<i); 
        row[r] ^=mask;
        col[c] ^=mask;
        mat[r/3][c/3] ^=mask;
        board[r][c]= i;

        count+=fill_sudoku(board,bno+1);

        row[r] ^=mask;
        col[c] ^=mask;
        mat[r/3][c/3] ^=mask;
        board[r][c]= 0;
    }
    }else{
        count+=fill_sudoku(board,bno+1);
    }

    return count;
}
vector<int> char_value_for_cryp(26,0);
int no_used=0;
int cryptarith(){

    for(int i=0;i<9;i++){

    }
}
int main(){

    return 0;
}