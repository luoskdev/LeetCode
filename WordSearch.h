/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *************************************/
 
 
class Solution {
public:
    vector<vector<int> > visited;
    bool exist(vector<vector<char> > &board, string word) 
    {
        int rows = board.size(), cols = board[0].size();
        visited.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            visited[i].resize(cols);
            for (int j = 0; j < cols; ++j)
            {
                visited[i][j] = 0;
            }
        }
        
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (existRe(board, rows, cols, i, j, word, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool existRe(vector<vector<char> > &board, int rows, int cols, int x, int y, string word, int pos)
    {
        if (pos == word.length()) return true;
        if (x < 0 || y < 0 || x == rows || y == cols || visited[x][y] == 1) return false;
        if (board[x][y] != word[pos]) return false;
        
        visited[x][y] = 1;
        
        bool res = existRe(board, rows, cols, x-1, y, word, pos+1) || existRe(board, rows, cols, x, y+1, word, pos+1)
                || existRe(board, rows, cols, x, y-1, word, pos+1) || existRe(board, rows, cols, x+1, y, word, pos+1);
        
        visited[x][y] = 0;
        
        return res;
    }
};