'''Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]'''
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #ok, thank friking god i solved this.
        #main logic: if the number in the array is nonzero, we bring it to the front of the array. The zeroes automatically go behind. 
        j=0
        for i in range(len(nums)):
            if(nums[i]!=0):
                temp=nums[i]
                nums[i]=nums[j]
                nums[j]=temp
                j+=1