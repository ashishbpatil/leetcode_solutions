class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) return;
        for(int i=0;i<matrix.size()/2;++i)
        {
            for(int j=i;j<matrix[i].size()-1-i;++j)
            {
                swap(matrix[i][j], matrix[j][matrix[j].size() - 1 - i]);
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][matrix[i].size() - 1 - j]); 
                swap(matrix[i][j], matrix[matrix.size() - 1 - j][i]);
            }
        }
    }
    
};
