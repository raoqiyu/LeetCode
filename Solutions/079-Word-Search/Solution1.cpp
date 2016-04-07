class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // DFS : column first
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word) == true)
                        return true;
                }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int row, int col, string& word){
        if(word.length() == 0)
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[0])
            return false;
        string s = word.substr(1);
        // The same letter cell may not be used more than once.
        char c = board[row][col];
        board[row][col] = '*';
        bool ret = dfs(board, row-1, col, s) || dfs(board, row+1, col, s) || dfs(board, row, col-1, s) || dfs(board, row, col+1, s);
        board[row][col] = c;
        return ret;
    }
};
