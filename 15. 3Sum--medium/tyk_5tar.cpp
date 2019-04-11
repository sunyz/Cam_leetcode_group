/*
排序后通过for循环遍历来固定一个数并取其负数作为后两个数的和从而转化为two_sum，用首尾双指针的方法来找到答案，
去重只需要去除第一个数和第二个数就好，并且当第一个数大于0时就不用继续遍历，因为三数之和必定会大于0.
执行用时 : 152 ms, 在3Sum的C++提交中击败了92.11% 的用户
内存消耗 : 15.6 MB, 在3Sum的C++提交中击败了82.88% 的用户
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>out;
        sort(nums.begin(),nums.end());
        if(nums.size() < 3 || *nums.begin() > 0 || *(nums.end()-1) < 0)
            return out;
        for (int i=0; i<nums.size()-2;i++){
            if ( nums[i]>0 ) break;
            if ( i>0 && nums[i]==nums[i-1] ) continue; // 第一个数去重
            int target = -nums[i];
            int j = i+1;
            int k = nums.size() - 1;
            while (j<k){
              if (nums[j] + nums[k] == target){
                  vector<int> x = {-target,nums[j],nums[k]};
                  out.push_back(x);
                  while(nums[++j] == nums[j-1]&& j < k); // 第二个数去重
              }
              else if (nums[j] + nums[k] > target){
                  k--;
              }
              else {
                  j++;
              }
            }
        } 
        return out;
    }
};
