// 执行用时 : 44 ms, 在Sort Array By Parity的C++提交中击败了93.00% 的用户
// 内存消耗 : 9.5 MB, 在Sort Array By Parity的C++提交中击败了94.72% 的用户
// 双指针,思路很简单（coding的时候需要保持清醒，不然debug会出很多笑话）
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int>::iterator A_begin = A.begin();
        vector<int>::iterator A_end = A.end();
        while (A_begin < A_end) {
            if ((*A_begin) % 2 == 0) {
                A_begin++;
            } else {
                int tmp = *A_begin;
                *A_begin = *(A_end - 1);
                *(A_end - 1) = tmp;
                A_end--;
            }
        }
        return A;
    }
};