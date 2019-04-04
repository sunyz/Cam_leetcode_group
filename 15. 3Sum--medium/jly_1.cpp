/**
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.

这道题我第一反应是使用第一题two sum的思路，先建一个unordered_map,然后便利所有数字对，在map中查找其和的相反数。
但是其实这个题的约束相当坑爹，不能有重复的三元组，-1 0 1 和0 -1 1视为一个。而且原数组中还有重复的数字，重复的数字可以算两次。比如-1 -1 2
这就使得这个思路非常蹩脚。我试过使用set解决，但是发现由于有重复数字不能行得通。
所以最后我只好加了个查重，就是那个愚蠢的判断。
这里还是把我的代码贴上来，前面的测试都通过了，但后面的超过了时间限制。网上的答案思路是要先排序。
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // construct a map
        unordered_map<int, int> m;
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        //set<set<int>> res_set;
        for (int i= 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (m.count(-nums[i] - nums[j]) && (i < m[-nums[i] - nums[j]]) && (j < m[-nums[i] - nums[j]])) {
                    vector<int> r = {nums[i], nums[j], -nums[i] - nums[j]};
                    //set<int> r = {nums[i], nums[j], -nums[i] - nums[j]};
                    // still has replicate triplets
                    bool insert = true;
                    //cout << "hhh i = " << i << " j= " << j<<endl;
                    for (auto iter : res) {
                        if ((r[0] == iter[1] && r[1] == iter[2] && r[2] == iter[0]) ||
                            (r[0] == iter[0] && r[1] == iter[2] && r[2] == iter[1]) ||
                            (r[0] == iter[1] && r[1] == iter[0] && r[2] == iter[2]) ||
                            (r[0] == iter[2] && r[1] == iter[0] && r[2] == iter[1]) ||
                            (r[0] == iter[2] && r[1] == iter[1] && r[2] == iter[0]) ||
                            (r[0] == iter[0] && r[1] == iter[1] && r[2] == iter[2])) {
                            insert = false;
                            break;
                        }
                    }
                    //cout << "sss";
                    if (insert) {  
                        res.push_back(r);
                        //cout << "here"<< endl;
                    }
                    //res_set.insert(r);
                }
            }
        }
        
        /*
        cout << res_set.size() << endl;
        for (auto iter : res_set) {
            vector<int> r(3);
            copy(iter.begin(), iter.end(), r.begin());
            res.push_back(r);
        }
        */
        return res;
    }
};
