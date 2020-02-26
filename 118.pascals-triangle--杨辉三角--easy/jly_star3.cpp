class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows < 1)
           return ret;
        ret.push_back(vector<int>(1,1));
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; j++) {
                int sum = ret[i-1][j-1] + ret[i-1][j];
                row.push_back(sum);
            }
            row.push_back(1);
            ret.push_back(row);

        }
        
        return ret;


    }
};
