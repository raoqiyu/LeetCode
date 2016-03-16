class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        // DFS : column first search
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(sub,false,sizeof(sub));
        // Initialize marked array
        for(int r = 0; r < 9; r++)
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '0';
                int sub_idx = (r/3)*3 + c/3;
                row[r][num] = col[c][num] = sub[sub_idx][num] = true;
            }
        dfs(board,0,0);
    }
private:
    bool row[10][10], col[10][10], sub[10][10];
    bool flag = 0;
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if(flag) return;
        // column first, if r is 9 then c is already 9, so we just check r
        if(r >= 9){
            // no more move
            flag = true;
            return;
        }
        // if this is not a unfilled position, continue
        if(board[r][c] != '.'){
            if(c < 8) dfs(board, r, c+1);
            else dfs(board, r+1, 0);
            if(flag) return;
        }else{
            // else consider digits from 1 to 9
            int sub_idx = (r/3)*3 + c/3;
            for(int num = 1; num <= 9; num++){
                if(!row[r][num] && !col[c][num] && !sub[sub_idx][num]){
                    board[r][c] = num + '0';
                    row[r][num] = col[c][num] = sub[sub_idx][num] = true;
                    if(c < 8) dfs(board, r, c+1);
                    else dfs(board, r+1, 0);
                    row[r][num] = col[c][num] = sub[sub_idx][num] = false;
                    if(flag) return;
                }
            }
            board[r][c] = '.';
        }
        return ;
    }
};
