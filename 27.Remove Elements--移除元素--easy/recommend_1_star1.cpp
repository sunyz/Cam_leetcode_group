// 一个较为推荐的算法，更加直观
// 不需要移位置，只要依次访问，然后原位覆盖写

// 执行用时 : 8 ms, 在Remove Element的C++提交中击败了25.86% 的用户
// 内存消耗 : 8.4 MB, 在Remove Element的C++提交中击败了0.39% 的用户

// 不过效果也只是star1 的。。。。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int i=0;
        int j=-1;
        while(++j<nums.size()){
            if(nums[j]!=val){
                nums[i++]=nums[j];
            }
        }
       return i;
        
    }
};