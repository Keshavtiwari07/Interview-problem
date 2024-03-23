class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int Size = nums.size();
        for(int i = 1; i < Size; i++){
            nums[i] += nums[i-1];
        }

        // case1 : maxSum without circular array
        int minTillNow = nums[0] > 0 ? 0 : nums[0];
        int max1 = nums[0];
        for(int i = 1; i < Size; i++){
            max1 = max(max1, (nums[i] - minTillNow));
            max1 = max(max1, nums[i]-nums[i-1]); // if current number itself is maximum
            minTillNow = nums[i] < minTillNow ? nums[i] : minTillNow;
        }

        // case2 : maxSum considering sub array from [i+1 to n] + [0 to maxSumIndex]
        int maxFromZero = nums[0];
        int max2 = nums[Size-1];
        int sum_i_to_n = 0;
        for(int i = 0; i < Size; i++){
            maxFromZero = max(nums[i], maxFromZero);
            sum_i_to_n = nums[Size-1]-nums[i];
            max2 = max(max2, maxFromZero + sum_i_to_n);
        }

        return max(max1, max2);
    }
};