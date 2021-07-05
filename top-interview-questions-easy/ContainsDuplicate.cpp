class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> check(nums.begin(), nums.end());
        if(nums.size() == check.size())
        {
            return false;
        }
        else
        {
            return true;                
        }
    }
};
