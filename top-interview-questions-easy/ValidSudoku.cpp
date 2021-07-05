class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row and colum check
        for(int i = 0; i< 9; ++i)
        {
            int row[10] = {0};
            int clm[10] = {0};
            for(int j = 0; j<9;++j)
            {
                if(board[i][j] != '.')
                {
                    ++row[board[i][j] - '0'];
                    if(row[board[i][j] - '0'] > 1)
                    {
                        return false;
                    }
                }
                if(board[j][i] != '.')
                {
                    ++clm[board[j][i] - '0'];
                    if(clm[board[j][i] - '0'] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        // 3x3 box check
        for(int i = 0; i< 9; i+=3)
        {
            for(int j = 0; j<9;j+=3)
            {
                int box[10] = {0};
                for(int k =0;k<3;++k)
                {
                    for(int l=0;l<3;++l)
                    {
                        if(board[i+k][j+l] != '.')
                        {
                            ++box[board[i+k][j+l] - '0'];
                            if(box[board[i+k][j+l] - '0'] > 1)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
