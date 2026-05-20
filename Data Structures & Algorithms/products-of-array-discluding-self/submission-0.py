class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out, p = [0] * len(nums), 1
        
        for i in range(len(nums)):
            out[i] = p
            p *= nums[i]

        p = 1
        for i in range(len(nums))[::-1]:
            out[i] *= p
            p *= nums[i]

        return out