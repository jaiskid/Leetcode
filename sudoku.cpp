#include<bits/stdc++.h>
using namespace std;
bool findemptycell(const vector<vector<char>>&board,size_t &row,size_t &col){
	for(row=0;row<board.size();++row)
		for(col=0;col<board[row].size();++col)
		if(board[row][col]=='.')
		return true;
	return false;
}
bool isSafe(const vector<vector<char>>&board,size_t row,size_t col,char c){
	for(size_t i=0;i<9;++i){
	if(board[row][i]==c) return false;
	if(board[i][col]==c) return false;
	if(board[row/3 *3 + i/3][col/3*3+i%3]==c) return false;
	}
	return true;
}
bool solvesudoku(vector<vector<char>>&board){
	size_t row=0,col=0;
	if(!findemptycell(board,row,col)) return true;
	for(char c:{'1','2','3','4','5','6','7','8','9'})
	if(isSafe(board,row,col,c)){
	board[row][col]=c;
	if(solvesudoku(board)) return true;
	board[row][col]='.';
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	vector<vector<char>> board(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			board[i].push_back(ch);
		}
	}
	solvesudoku(board);
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}