// 双指针，比较简单，写的时候细心一点就好

// 执行用时 : 20 ms, 在Flipping an Image的C++提交中击败了92.41% 的用户
// 内存消耗 : 9.2 MB, 在Flipping an Image的C++提交中击败了0.00% 的用户
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // A[i][j]
        for (int i = 0; i < A.size(); i++) {
            auto iter_begin = A[i].begin();
            auto iter_end = A[i].end();
            // A[i] == 2n --- end - start >= 1; A[i] == 2n + 1 --- end - start  
            while (iter_end - iter_begin >= 1) {
                int tmp = !(*iter_begin);
                *iter_begin = !(*(iter_end - 1));
                *(iter_end - 1) = tmp;
                iter_begin++;
                iter_end--;
            }
        }
        return A;
    }
};