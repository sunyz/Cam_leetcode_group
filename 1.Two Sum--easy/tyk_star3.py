#执行用时 : 52 ms, 在Two Sum的Python提交中击败了69.55% 的用户
#内存消耗 : 13 MB, 在Two Sum的Python提交中击败了0.96% 的用户
#好像算法跟syz的是一样的...
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            if nums[i] not in d:
                d[target-nums[i]] = i
            else:
                return [i,d[nums[i]]]
