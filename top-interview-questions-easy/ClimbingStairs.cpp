class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        int ways[n+1];
        ways[0] = ways[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            ways[i] = ways[i-2] + ways[i-1];
        }
        
        return ways[n];
    }
};
