void Dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        if (min(i, j) < 0 || i >= m || j >= n || board[i][j] != 'O'){
            return ;
        }
        board[i][j] = 'T';

        Dfs(board, i - 1, j, m, n);
        Dfs(board, i + 1, j, m, n);
        Dfs(board, i, j - 1, m, n);
        Dfs(board, i, j + 1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            Dfs(board, i, 0, m, n);
            Dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++)
        {
            Dfs(board, 0, j, m, n);
            Dfs(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }