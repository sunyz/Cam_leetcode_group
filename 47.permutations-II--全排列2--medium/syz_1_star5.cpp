/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-21 16:55:57
 * @LastEditTime: 2019-04-21 21:24:52
 */


//  * @Description: 用的是标准的递归的思想
//  * 具体解释请参考   https://blog.csdn.net/lemon_tree12138/article/details/50986990
//  * 同样的思路，解释的更加清楚
//  * 就是在递归之前去重，只在重复的最后一次出现时才递归

// 执行用时 : 36 ms, 在Permutations II的C++提交中击败了95.81% 的用户
// 内存消耗 : 9.8 MB, 在Permutations II的C++提交中击败了91.97% 的用户

class Solution {
public:
    void sub_permute(vector<int> &nums, vector<int>& tmp, int start, vector<vector<int>>& ans) {
        if (nums.size() == start+1) {
             tmp.push_back(nums[start]);
             ans.push_back(tmp);
             tmp.pop_back();
        } else {
            for (int i = start; i< nums.size(); i++) {
                bool flag = true;
                for (int mm=i+1; mm<nums.size(); mm++) {
                    if (nums[mm] == nums[i]) {
                        flag = false;
                        //std::cout<<"mm sub"<<mm<<std::endl;
                        //std::cout<<"i sub"<<i<<std::endl;
                        break;
                    }
                }
                if (flag) {
                    tmp.push_back(nums[i]);
                    int a = nums[i];
                    nums[i] = nums[start];
                    nums[start] = a;
                    sub_permute(nums, tmp, start+1, ans);
                    tmp.pop_back();
                    nums[start] = nums[i];
                    nums[i] = a;
                } else {
                    continue;
                }  
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        vector<int> tmp;
        if (nums.size() == 1) {
            tmp.push_back(nums[0]);
            ans.push_back(tmp);
            return ans;
        }
        for (int i=0; i<nums.size(); i++) {
            bool flag = true;
            for (int mm=i+1; mm<nums.size(); mm++) {
                if (nums[mm] == nums[i]) {
                    flag = false;
                    //std::cout<<"mm mian"<<mm<<std::endl;
                    break;
                }
            }
            if (flag) {
                int a = nums[i];
                nums[i] = nums[0];
                nums[0] = a;
                tmp.push_back(nums[0]);
                sub_permute(nums, tmp,1,ans);
                //ans.push_back(tmp);
                tmp.clear();
                nums[0] = nums[i];
                nums[i] =a;
            } else {
                continue;
            }
            
        }

        
        return ans;
    }
};