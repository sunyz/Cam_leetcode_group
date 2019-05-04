/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明: 
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

执行用时 : 20 ms, 在Kth Largest Element in an Array的C++提交中击败了79.88% 的用户
内存消耗 : 9.6 MB, 在Kth Largest Element in an Array的C++提交中击败了34.71% 的用户
话说priority_queue为什么greater表示小顶堆。。
这道题使用io黑科技会有奇效，同样是以下代码，加上
const static auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
以后就变成5star了。甚至你直接调用std::sort效果都不错。。
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //vector<int> res(k, INT_MIN);
        priority_queue<int, vector<int>, greater<int> > heap;
        for (int i = 0; i < k; i++)
            heap.push(INT_MIN);
        for (auto iter : nums) {
            if (iter > heap.top()) {
                heap.push(iter);
                heap.pop();
            }
        }
        return heap.top();
    }
};
