// 不看参考很难想出常数空间复杂度的方法，我的是把需要置零的行或列的第一个数置零，但第一行第一列这个点会有歧义，容易出bug
/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
执行用时 :
104 ms
, 在所有 C++ 提交中击败了
29.27%
的用户
内存消耗 :
11.4 MB
, 在所有 C++ 提交中击败了
58.10%
的用户
*/
class Solution {
public:
    void printMat(vector<vector<int>>& matrix) {
      for (int i = 0 ; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          cout << matrix[i][j] << " ";
        }
        cout << endl;
        
      }

    }
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      if (m == 0) return;
      int n = matrix[0].size();
      if (n == 0) return;
      bool first_row_set_zero = false;
      
      for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0) {
          first_row_set_zero = true;
          break;
        }
      // set first
      for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }
      // printMat(matrix);
      
      // set 0
      for (int i = 1; i < m; i++) { // care for bug here if i == 0
        if (matrix[i][0] == 0) {
          for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
          }
        }
      }
      // printMat(matrix);
      for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
          for (int i = 0; i < m; i++) {
            matrix[i][j] = 0;
          }
        }
      }
      
      if (first_row_set_zero)
        for (int j = 0; j < n; j++)
          matrix[0][j] = 0;
    }
  
};
