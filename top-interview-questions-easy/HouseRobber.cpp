class Solution {
public:
    // f(n) = max((f(n-2) + nums[n]), f(n-1))
    // prev = f(n-2)
    // cur = f(n-1)
    int rob(vector<int>& nums) {
        int ans = 0;
        int cur = 0, prev = 0;
        for(int i =0; i< nums.size();++i)
        {
            ans = max(prev + nums[i], cur);
            prev = cur;
            cur = ans;
        }
        return ans;
    }
};
