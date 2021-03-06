/**
 * 2. 两个数的最大乘积
 * 给你一个整型数组 nums ，在数组中找出由两个数组成的最大乘积，并输出这个乘积。

 * 示例 1：
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：12
 * 示例 3：
 * 
 * 输入：nums = [-1,-2,-3]
 * 输出：6
 * 
 * 方法一：排序
 * 首先将数组排序。
 * 
 * 如果数组中全是非负数，则排序后最大的两个数相乘即为最大乘积
 * 
 * 如果全是非正数，则排序后最小的两个数乘积即为最大乘积
 * 
 * 如果数组中有正数有负数，则最大乘积即有可能是最小的两个数乘积，也可能是最大两个数的乘积。
 * 
 * 综上，我们在给数组排序后，最大乘积为：最大两个数的乘积 or 最小两个数的乘积。
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 2] * nums[n - 1], nums[0] * nums[1]);
    }
};