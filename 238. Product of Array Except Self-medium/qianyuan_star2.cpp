// 昨天写到自闭，这个题目有点不好想。一开始答案都看不懂，后来想明白了，也就知道怎么解答了。
// 关键点：题干 + 2次迭代（减少计算量，满足o(n)的时间要求）
// 后面还可以做一些小的优化，标准答案中只用了两个for循环，时间开销o(2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // A: from left to right
        int A[nums.size()];
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                A[i] = 1;
            } else {
                tmp *= nums[i - 1];
                A[i] = tmp;
            }
        }
        // B: from right to left
        int B[nums.size()];
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == (nums.size() - 1)) {
                B[i] = 1;
            } else {
                tmp *= nums[i + 1];
                B[i] = tmp;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = A[i] * B[i];
        }
        return nums;
    }
};