#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> out;
void justDoIt(vector<string> &board,int n,int row,int col){
    cout<<"justDoIt() for "<<row<<" : "<<col<<endl;
    
    for(int i=0;i<board[row].size();i++){
        if(board[row][i] == '.') continue;
        else return;
    }
    for(int i=0;i<board[row].size();i++){
        if(board[i][col] == '.') continue;
        else return;
    }
    int row_ = row-1;
    int col_ = col-1;
    while(row_ >= 0 && col_ >= 0) if(board[row_--][col_--] == 'Q') return;
    row_ = row-1;
    col_ = col+1;
    while(row_ >= 0 && col_ < board[row].size()) if(board[row_--][col_++] == 'Q') return;
    row_ = row+1;
    col_ = col-1;
    while(row_ < board.size() && col_ >= 0) if(board[row_++][col_--] == 'Q') return;
    row_ = row+1;
    col_ = col+1;
    while(row_ < board.size() && col_ < board[row].size()) if(board[row_++][col_++] == 'Q') return;
    cout<<"All check Done \n";
    
    board[row][col] = 'Q';
    row++;

    cout<<"Board now :: "<<endl;
    for(auto x:board) cout<<x<<endl;
    if(row == n){
        out.push_back(board);
        board[row-1][col] = '.';
        return;
    }
    
    for(int i=0;i<n;i++) justDoIt(board,n,row,i);
    
    board[row][col] = '.';
}
vector<vector<string>> solveNQueens(int n) {
    for(int i=0;i<n;i++){
        cout<<"Calling for 0,"<<i<<endl;
        vector<string> temp(n,string(n,'.'));
        cout<<"calling justDoIt()\n";
        justDoIt(temp,n,0,i);
        // bool tempOut = justDoIt(temp,n,0,i);
        // if(tempOut){
        //     out.push_back(temp);
        //     cout<<"OUTPUT :::::: \n";
        //     for(auto x:temp) cout<<x<<endl;
        // }
        // else cout<<"It's FALSE\n";
    }
    return out;
}
int main(){
    vector<vector<string> > out = solveNQueens(5);
    for(int i=0;i<out.size();i++){
        for(auto x:out[i]) cout<<x<<endl;
        cout<<endl;
    }
    return 0;
}
/*
[
    ["Q....","..Q..","....Q",".Q...","...Q."],
    ["Q....","...Q.",".Q...","....Q","..Q.."],
    [".Q...","...Q.","Q....","..Q..","....Q"],
    [".Q...","....Q","..Q..","Q....","...Q."],
    ["..Q..","Q....","...Q.",".Q...","....Q"],
    ["..Q..","....Q",".Q...","...Q.","Q...."],
    ["...Q.","Q....","..Q..","....Q",".Q..."],
    ["...Q.",".Q...","....Q","..Q..","Q...."],
    ["....Q",".Q...","...Q.","Q....","..Q.."],
    ["....Q","..Q..","Q....","...Q.",".Q..."]]
*/