#include <vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>> &board) 
	{
		vector<vector<int> > visited;
		for (int i = 0; i < board.size(); ++i)
		{
			visited.push_back(vector<int>(board[i].size(), 0));
		}

		for (int i = 0; i < board.size(); ++i)
		{
			solveRe(board, i, 0, visited);
			solveRe(board, i, board.size()-1, visited);
		}
		for (int i = 0; i < board[0].size(); ++i)
		{
			solveRe(board, 0, i, visited);
			solveRe(board, board[0].size()-1, i, visited);
		}

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] == 'O' && visited[i][j] == 0)
				{
					board[i][j] = 'X';
				}
			}
		}
	}

	void solveRe(vector<vector<char> > &board, int row, int col, vector<vector<int> > &visited)
	{
		if (row < 0 || col < 0 || row == board.size() || col == board[0].size() 
			|| visited[row][col] == 1 || board[row][col] == 'X')
			return;

		visited[row][col] = 1;

		solveRe(board, row - 1, col, visited);
		solveRe(board, row, col + 1, visited);
		solveRe(board, row + 1, col, visited);
		solveRe(board, row, col - 1, visited);
	}
};