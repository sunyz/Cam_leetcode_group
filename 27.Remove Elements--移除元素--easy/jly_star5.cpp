/**
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素

执行用时 : 8 ms, 在Remove Element的C++提交中击败了95.95% 的用户
内存消耗 : 8.7 MB, 在Remove Element的C++提交中击败了73.19% 的用户
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> s;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                count++;
                s.push(i);
            } else {
                // cout << nums[i] ;
                if(!s.empty()) {
                    // cout << "here" << endl;
                    nums[s.front()] = nums[i];
                    s.push(i);
                    s.pop();
                }
            }
            
        }
        return nums.size() - count;
    }
};
