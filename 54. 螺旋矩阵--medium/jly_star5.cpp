/**
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
执行用时 : 8 ms, 在Spiral Matrix的C++提交中击败了95.64% 的用户
内存消耗 : 8.7 MB, 在Spiral Matrix的C++提交中击败了26.24% 的用户
分解成四个阶段并循环起来
*/
class Solution {
public:
    enum class Status {
        RIGHT,
        UP,
        DOWN,
        LEFT,
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int x = 0;
        int y = 0;
        int x_limit = 0;
        int y_limit = 1;
        Status s = Status::RIGHT;
        while(res.size() < matrix.size() * matrix[0].size()) {
            switch (s) {
                case Status::RIGHT:
                    //cout << "in right" << endl;
                    for (int i=0; i < (int)matrix[0].size() - x_limit; i++) {
                        //cout << "x=" << x << " y=" << y << endl;
                        res.push_back(matrix[y][x]);
                        x++;
                    }
                    x--;y++;
                    s = Status::DOWN;
                    x_limit++;
                    break;
                case Status::DOWN:
                    //cout << "in down" << endl;
                    for (int i=0; i < (int)matrix.size() - y_limit; i++) {
                        //cout << "x=" << x << " y=" << y << endl;
                        res.push_back(matrix[y][x]);
                        y++;
                    }
                    y--;x--;
                    s = Status::LEFT;
                    y_limit++;
                    break;
                case Status::LEFT:
                    //cout << "in left" << endl;
                    for (int i=0; i < matrix[0].size() - x_limit; i++) {
                        //cout << "x=" << x << " y=" << y << endl;
                        res.push_back(matrix[y][x]);
                        x--;
                    }
                    x++;y--;
                    s = Status::UP;
                    x_limit++;
                    break;
                case Status::UP:
                    //cout << "in up" << endl;
                    for (int i = 0 ; i < matrix.size() - y_limit; i++) {
                        //cout << "x=" << x << " y=" << y << endl;
                        res.push_back(matrix[y][x]);
                        y--;
                    }
                    y++;x++;
                    s = Status::RIGHT;
                    y_limit++;
                    break;
                default:
                    break;
            }
        }
        return res;
    }
};
