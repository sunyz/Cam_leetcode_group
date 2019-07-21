/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 超出时间限制的解法，把set换成marked数组依然超出，虽然我看其他人的答案也是DFS，但这个真的好容易超时啊，后来我加了一些剪枝，把cout删掉了，才能过
class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0)
            return false;
        bool res = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                set<pair<int, int>> chars;
                res = find(i, j, board, word, 0, chars);
                if (res)
                    break;
            }
            if (res)
                break;
        }
        return res;
    }
    bool find(int i, int j, vector<vector<char>>& board, string& word, int curr_char, set<pair<int, int>> characters) {
        cout << " i = " << i << " j = " << j << endl;
        int curr_i = i;
        int curr_j = j;
        bool ret = false;
        if (curr_char >= word.size())
            return true;
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
            return false;
        if (board[curr_i][curr_j] != word[curr_char] || characters.count(make_pair(i, j)))
            return false;
        
        characters.insert(make_pair(i, j));
        bool res1 = find(i + 1, j, board, word, curr_char+1, characters);
        if (res1)
            return true;
        bool res2 = find(i, j + 1, board, word, curr_char+1, characters);
        if (res2)
            return true;
        bool res3 = find(i - 1, j, board, word, curr_char+1, characters);
        if (res3)
            return true;
        bool res4 = find(i, j - 1, board, word, curr_char+1, characters);
        ret = res1 || res2 || res3 || res4;
        return ret;
    }
    
};
