#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> res;
bool  isValid ( int row, int col, const vector < int > & queens) {
        for ( int queen_col = 0 , r = row- 1 , lc = col- 1 , rc = col + 1 ; r>= 0 ; --r, --lc, ++ rc) {
            queen_col = queens [r];
            if (queen_col == col || queen_col == lc || queen_col == rc) return  false ;
        }
        return  true ;
    }
void solveNqueen(int row,vector<int> queen){
	int size=queen.size();
	if(row==size){
		vector<string> solution(size,string(size,'.'));
		for(int r=0;r<size;++r)
			solution[r][queen[r]]='Q';
			res.push_back(solution);
		}else for(int col=0;col<size;++col){
			queen[row]=col;
			if(isValid(row,col,queen)) solveNqueen(row+1,queen);

		}
}



vector<vector<string>> solveNqueen(int n){
	vector<int> queen(n,0);
	solveNqueen(0,queen);
	return res;
}
int main(){
	int n;
	cin>>n;
	solveNqueen(n);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"  ";
			cout<<endl;
		}
		cout<<endl;
	}
}
