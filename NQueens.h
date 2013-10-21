/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-21
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' 
 * placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *  "Q...",
 *  "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *************************************/
 
 
 
class Solution {
public:
	vector<vector<string> > res;
	vector<vector<string> > solveNQueens(int n) 
	{
	    res.clear();
		vector<vector<char> > board;
		if (n == 0) return res;
		
		board.resize(n);
		for (int i = 0; i < n; ++i)
		{
			board[i].resize(n);
			for (int j = 0; j < n; ++j)
			{
				board[i][j] = '.';
			}
		}

		solveNQueensRe(board, n, 0);

		return res;
	}

	void solveNQueensRe(vector<vector<char> > &board, int n, int col)
	{
		if (col == n) return addRes(board);
		int i = 0, j = 0, k = 0;
		for(i = 0; i < n; ++i)
		{
			for (j = 0; j < col && board[i][j] == '.'; ++j);
			if (j != col) continue;
			for (j = i, k = col; j >= 0 && k >= 0 && board[j][k] == '.'; --j,--k);
			if (j >= 0 && k >= 0) continue;
			for (j = i, k = col; j < n && k >= 0 && board[j][k] == '.'; ++j, --k);
			if (j < n && k >= 0) continue;

			board[i][col] = 'Q';
			solveNQueensRe(board, n, col+1);
			board[i][col] = '.';
		}
	}

	void addRes(vector<vector<char> > &board)
	{
		vector<string> result;
		for (int i = 0; i < board.size(); i++)
		{
			string temp(board[i].begin(), board[i].end());
			result.push_back(temp);
		}
		res.push_back(result);
	}
};