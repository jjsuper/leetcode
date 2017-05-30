class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size();
        int n=m? board[0].size(): 0;
        
        queue<vector<int>> q;
        q.push(click);
        
        while(!q.empty()) {
            vector<int> cur=q.front();
            q.pop();
            
            if(board[cur[0]][cur[1]]=='M') {
                board[cur[0]][cur[1]]='X';
            }
            else {
                int Mcnt=0;
                for(int i=max(0, cur[0]-1); i<min(m, cur[0]+2); ++i)
                    for(int j=max(0, cur[1]-1); j<min(n, cur[1]+2); ++j) {
                        if(board[i][j]=='M') Mcnt++;
                    }
            
                if(Mcnt) board[cur[0]][cur[1]]=Mcnt+'0'; 
                else {
                    board[cur[0]][cur[1]]='B';
                    for(int i=max(0, cur[0]-1); i<min(m, cur[0]+2); ++i)
                        for(int j=max(0, cur[1]-1); j<min(n, cur[1]+2); ++j) {
                        if(board[i][j]=='E') {
                            q.push(vector<int>{i, j});
                            board[i][j]='B'; //memory limit
                        }  
                    }
                }
            }
        }
        
        return board;
    }
};