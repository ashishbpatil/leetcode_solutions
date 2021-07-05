class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zCount = 0;
        for(int i=0; i<nums.size();++i)
        {
            if(nums[i] == 0)
            {
                ++zCount;
            }else{
                nums[i-zCount] = nums[i];
                if(zCount > 0)
                {
                    nums[i] = 0;
                }
            }
        }
    }
};
