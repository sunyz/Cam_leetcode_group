// 执行用时 : 256 ms, 在Next Greater Element II的C++提交中击败了38.12% 的用户
// 内存消耗 : 12.8 MB, 在Next Greater Element II的C++提交中击败了78.74% 的用户
// 效率还可以，但是写的很丑。标准答案使用栈和循环，表达更加简洁，技巧性很强，值得学习
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int j;
            result.push_back(-1);
            if (i == (nums.size() - 1)) {
                j = 0;
            } else {
                j = i + 1;
            }
            while (i != j) {
                if (nums[j] > nums[i]) {
                    result.pop_back();
                    result.push_back(nums[j]);
                    break;
                }
                if (j == (nums.size() - 1)) {
                    j = 0;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};