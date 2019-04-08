//执行用时 : 144 ms, 在Squares of a Sorted Array的C++提交中击败了19.76% 的用户
//内存消耗 : 14.1 MB, 在Squares of a Sorted Array的C++提交中击败了100.00% 的用户
// 方法：双指针，为了逻辑简单，内存占用比较高
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>::iterator begin = A.begin();
        vector<int>::iterator end = A.end() - 1;
        vector<int> result(A.size());
        vector<int>::iterator result_t = result.end() - 1;
        while (end - begin + 1 > 0) {
            if (abs(*begin) >= abs(*end)) {
                *result_t = pow(*begin, 2);
                begin++;
            } else {
                *result_t = pow(*end, 2);
                end--;
            }
            result_t--;
        }
        A.swap(result);
        return A;
    }
};
