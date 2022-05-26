class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	// o(1) space and o(n) time
        if(nums.size() == 1) return nums[0];
        int maxSum = numeric_limits<int>::min();
        int tmpSum = 0;
        for(int i =0; i< nums.size();++i)
        {
            tmpSum += nums[i];
            if(maxSum < tmpSum)
            {
                maxSum = tmpSum;
            }
            if(tmpSum < 0)
            {
                tmpSum = 0;
            }
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // let m[i] be the max sum upto i
        // for m[i+1] = max(nums[i+1], nums[i+1]+m[i])
        // O(1) Space
        int ans = nums[0];
        int sum = 0;
        for(auto&& n:nums) {
            sum = max(n, sum+n);
            if(sum>ans) ans = sum;
        }
        return ans;
    }
};
