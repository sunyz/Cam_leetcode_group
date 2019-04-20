// 执行用时 : 16 ms, 在Next Greater Element I的C++提交中击败了97.15% 的用户
// 内存消耗 : 9.2 MB, 在Next Greater Element I的C++提交中击败了60.57% 的用户
// 思路简单，Nothing to say,标准答案使用栈，但表达太罗嗦了
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums2.size(); i++) {
            int j = i + 1;
            /*while((nums2[i] >= nums2[j]) && (j < nums2.size())) {
                j++;
            }*/
            for(int j = i + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums2[i]) {
                    map[nums2[i]] = nums2[j];
                    break;
                }
            } 
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(map.count(nums1[i]) > 0) {
                // nums1[i] = map.find(nums1[i])->second;
                nums1[i] = map[nums1[i]];
            } else {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};