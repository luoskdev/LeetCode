/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-12
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled 
 * with the character '.'.
 *
 *
 * A partially filled sudoku which is valid.
 *************************************/
 

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) 
    {
        const int N = 9;
        int row = 0, cols[N] = {0}, box[N] = {0};
        
        for (int i = 0; i < N; ++i)
        {
            row = 0;
            for (int j = 0; j < N; ++j)
            {
                if (board[i][j] == '.') continue;
                
                int bit = (1 << board[i][j] - '1');
                int box_index = i / 3 * 3 + j / 3;
                
                if (row & bit || cols[j] & bit || box[box_index] & bit)
                    return false;
                row |= bit;
                cols[j] |= bit;
                box[box_index] |= bit;
            }
        }
        
        return true;
    }
};