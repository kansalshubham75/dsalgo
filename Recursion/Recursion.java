package Recursion;

import java.util.ArrayList;
class Recursion{

    //==============================Permutations of a string==========================//

    public static void permutation_01(String str,String ans) {
        if(str.length()==0){
            System.out.println(ans);
            return;
        }

        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            String nstr= str.substring(0,i) + str.substring(i+1);
            permutation_01(nstr, ans + ch);
        }
    }


    public static void permutation_02(String str, String ans) {
        if(str.length()==0){
            System.out.println(ans);
            return;
        }
        int[] vis=new int[26];
        for(int i=0;i<str.length();i++){
        String nstr= str.substring(0,i)+str.substring(i+1);
        char ch=str.charAt(i);
        if(vis[ch-'a']!=1){
            vis[ch-'a']=1;
            permutation_02(nstr, ans + ch);
        }

    }
    }
public static ArrayList<String> substr(String str){
if(str.length()==0){
    ArrayList<String> base= new ArrayList<>();
    base.add("");
    return base;
}

String nstr=str.substring(1);
char ch=str.charAt(0);
ArrayList<String> recAns=substr(nstr);
ArrayList<String> myAns= new ArrayList<>(recAns);
for(int i=0;i<recAns.size();i++){
    myAns.add(ch + recAns.get(i));
}
return myAns;
}

public static Boolean isSafe(int nsr,int nsc,int[][] board) {
    if(nsr<0 || nsc<0 || nsr>=board.length || nsc>=board[0].length || board[nsr][nsc] == 1){
        return false;
    }
    return true;
}
public static int[][] dir={{-1,0},{1,0},{0,1},{0,-1}};
public static char[] directions={'U','D','R','L'};
public static int floodFill(int[][] board,int sr,int sc,int er,int ec,String ans) {
    if(sr==er && sc==ec){
        System.out.println(ans);
        return 1;
    }
    int count=0;
    board[sr][sc]=1;
    for(int i=0;i<dir.length;i++){
            int nsr=sr +dir[i][0];
            int nsc=sc +dir[i][1];
            if(isSafe(nsr,nsc,board)){
                count+=floodFill(board, nsr, nsc, er, ec, ans+ directions[i] + " ");
            
        }
    }
    board[sr][sc]=0;
    return count;
}
//========================RAT IN A MAZE================================//
public static void maze() {
    int[][] maze={{1, 0, 0, 0} , {1, 1, 0, 1} , {0, 1, 0, 0} , {1, 1, 1, 1}};
    //System.out.println(maze_01(maze,0,0,3,3,""));
    System.out.println(maze_02(maze,0,0,3,3,""));

}
public static Boolean isSafe_forMaze(int[][] maze,int nsr,int nsc,int er,int ec){
if(nsr<0 || nsc<0 || nsr>=maze.length || nsc>=maze[0].length || maze[nsr][nsc]==0)
    return false;
return true;
}
public static int[][] dir_for_maze={{0,1},{1,0}};
public static String[] directions_for_maze={"H","V"};
public static Boolean maze_01(int[][] maze,int sr,int sc,int er ,int ec,String ans) { //Horizontal & vertical
if(sr==er && sc==ec){
    System.out.println(ans);
    return true;
}
Boolean pathFound=false;
for(int i=0;i<dir_for_maze.length;i++){
int nsr = sr + dir_for_maze[i][0];
int nsc= sc + dir_for_maze[i][1];
if(isSafe_forMaze(maze, nsr, nsc, er, ec)){
   pathFound= maze_01(maze, nsr, nsc, er, ec, ans + directions_for_maze[i] + " ");
}
}
return pathFound;
}



public static int[][] dir_for_maze02={{0,1},{1,0},{1,1}};
public static String[] directions_for_maze02={"H","V","D"};
public static Boolean maze_02(int[][] maze,int sr,int sc,int er ,int ec,String ans) { //Horizontal vertical & diag
    if(sr==er && sc==ec){
        System.out.println(ans);
        return true;
    }
    Boolean pathFound=false;
    for(int i=0;i<dir_for_maze02.length;i++){
    int nsr = sr + dir_for_maze02[i][0];
    int nsc= sc + dir_for_maze02[i][1];
    if(isSafe_forMaze(maze, nsr, nsc, er, ec)){
       pathFound= maze_02(maze, nsr, nsc, er, ec, ans + directions_for_maze02[i] + " ");
    }
    }
    return pathFound;
    }

    public static void nQueenBit_best(int tnq,int rows,String ans) {
        
    }
 public static void solve() {
    //System.out.println(substr("abc"));
    //permutation_02("aaa", "");
    //System.out.println(floodFill(new int[4][4], 0, 0, 3, 3, ""));
    maze();
}

public static void main(String[] args) {
   solve();
}
}