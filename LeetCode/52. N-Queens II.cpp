#include<bits/stdc++.h>
using namespace std;
int count = 0;
void justDoIt(vector<string> &board,int n,int row,int col){
    cout<<"justDoIt() for "<<row<<" : "<<col<<endl;
    //Column
    for(int i=0;i<board[row].size();i++){
        if(board[row][i] == '.') continue;
        else return;
    }
    //Row
    for(int i=0;i<row;i++){
        if(board[i][col] == '.') continue;
        else return;
    }
    //Diagonal Left
    int row_ = row-1;
    int col_ = col-1;
    while(row_ >= 0 && col_ >= 0) if(board[row_--][col_--] == 'Q') return;
    //Diagonal Right
    row_ = row-1;
    col_ = col+1;
    while(row_ >= 0 && col_ < board[row].size()) if(board[row_--][col_++] == 'Q') return;
    /*
    Not needed as we have not yet placed any queen in lower rows.
    row_ = row+1;
    col_ = col-1;
    while(row_ < board.size() && col_ >= 0) if(board[row_++][col_--] == 'Q') return;
    row_ = row+1;
    col_ = col+1;
    while(row_ < board.size() && col_ < board[row].size()) if(board[row_++][col_++] == 'Q') return;
    */
    cout<<"All check Done \n";
    
    board[row][col] = 'Q';

    cout<<"Board now :: "<<endl;
    for(auto x:board) cout<<x<<endl;
    if(row+1 == n){
        ::count++;
        board[row][col] = '.';
        return;
    }

    for(int i=0;i<n;i++) justDoIt(board,n,row+1,i);
    
    board[row][col] = '.';
}
int totalNQueens(int n) {
    for(int i=0;i<n;i++){
        cout<<"Calling for 0,"<<i<<endl;
        vector<string> temp(n,string(n,'.'));
        cout<<"calling justDoIt()\n";
        justDoIt(temp,n,0,i);
    }
    return ::count;
}
int main(){
    cout<<totalNQueens(4)<<endl;
    return 0;
}
static bool fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return false;
}();