#include<iostream>
#include<vector>
using namespace std;

int coinInfiniteCombinations(vector<int>& coins,int idx, int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<coins.size();i++){
        if(tar-coins[i]>=0){
            count+=coinInfiniteCombinations(coins,i,tar-coins[i],ans + to_string(coins[i]) + " ");
        }
    }    
    return count;
}

int CoinPermutation(vector<int> &coins, vector<bool> &vis, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        if (tar - coins[i] >= 0 && !vis[i])
        {
            vis[i] = true;
            count += CoinPermutation(coins, vis, tar - coins[i], ans + to_string(coins[i]) + " ");
            vis[i] = false;
        }
    }

    return count;
}
int coinInfinitePermutation(vector<int>& coins, int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<coins.size();i++){
        if(tar-coins[i]>=0){
            count+=coinInfinitePermutation(coins,tar-coins[i], ans + to_string(coins[i]) + " ");
        }
    }    
    return count;
}

int queenCombinations(vector<int> &board,int idx,int tq,int qpsf,string ans){
    if(tq==qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
  
    for(int i=idx;i<board.size();i++){
        count+=queenCombinations(board , i+1 , tq,qpsf+1 ,ans+ "q"+to_string(qpsf)+"b"+to_string(i)+"  ");
    }
    return count;
}

int queenPermutations(vector<int> &board,vector<bool> &vis,int tq,int qpsf,string ans){
    if(tq==qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
  
    for(int i=0;i<board.size();i++){
        if(!vis[i]){
            vis[i]=true;
            count+=queenPermutations(board , vis , tq,qpsf+1 ,ans+ "q"+to_string(qpsf)+"b"+to_string(i)+"  ");
            vis[i]=false;
    }
    }
    return count;
}
vector<vector<int>> dir_for_nqueen={{0,-1},{-1,-1},{-1,0},{-1,1}};
bool isQueenSafe(vector<vector<int>> &boxes,int r,int c){
    int nr=0,nc=0;
   for(int dir=0;dir<dir_for_nqueen.size();dir++){
       for(int jump=1;jump<=boxes.size()-1,jump++){
           nr=r + jump*dir_for_nqueen[dir][0];
           nc=c + jump*dir_for_nqueen[dir][1];
           if(boxes[nr][nc]==1){
               return false; 
           }
       }
   } 
   return true;
}
int nQueen(vector<vector<int>> &boxes,int idx,int tq, int qpsf, string ans){
if(tq==qpsf){
    cout<<ans<<endl;
    return 1;
}


int count=0;
for(int i=idx;i<boxes.size()*boxes[0].size();i++){
    int r= i/boxes.size();
    int c= i%boxes.size();
    if(isQueenSafe(boxes,r,c)){
        boxes[r][c]=1;
        count+=nQueen(boxes,i+1,tq,qpsf+1,ans +"q"+ to_string(qpsf)+ "r"+ to_string(r) + "c" + to_string(c) +" ");
        boxes[r][c]=0;
    }
}
return count;
}



bool isSafe(int nsr,int nsc,vector<vector<int>>& board){
    if(nsr<0 || nsc<0 || nsr>=board.size() || nsc>=board[0].size() || board[nsr][nsc]==1)
        return false;
    return true;
}
vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
vector<char> directions={'U','D','R','L'};

int floodFill(vector<vector<int>>& board,int sr,int sc,int er,int ec,string ans){
if(sr==er && sc==ec){
    cout<<ans<<endl;
    return 1;
}
int count=0;
board[sr][sc]=1;
for(int d=0;d<dir.size();d++){
    int nsr=sr+dir[d][0];
    int nsc=sc+dir[d][1];
    if(isSafe(nsr,nsc,board)){
        count+=floodFill(board,nsr,nsc,er,ec,ans +directions[d] +" ");
    }
}
board[sr][sc]=0;
return count;
}


// board[sr][sc]=0;
// return count;
// }
// int row_=0;
// int col_=0;
// int diag_=0;
// int antiDiag_=0;

// bool isQueenSafe_bestWala(int col){
// if()
// }

// void mark_unmark_queen(int row,int col){
// row_ ^=(1<<row);
// col_ ^=(1<<col);
// diag_ ^=()
// }

// int nQueen_Best_Using_Bits(int row,int tnq,string ans){
//     if(tnq==0){
//         cout<<ans<<endl;
//         return 1;
//     }
//     int count=0;
//     for(int col=0;col<col_;col++){
//         if(isQueenSafe_bestWala()){
//             mark_unmark_queen(row,col);
//             count+=nQueen_Best_Using_Bits(row+1,tnq-1,ans + "(" + to_string(row) + "," + to_string(col) + ")");
//             mark_unmark_queen(row,col);
//         }
//     }
// return count;
// }
int main(){
    //vector<int> coins={2,3,5,7};
    vector<int> board(5,0);
    vector<bool> vis(5,false);
    vector<vector<int>> boxes();
    //cout<<coinInfinitePermutation(coins,10,"");
    //cout<<queenPermutations(board,vis,3,0,"");
    //cout<<nQueen()
    return 0;
}