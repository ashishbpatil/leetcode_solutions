class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        bool flag = false;
        for(int i =0; i < n; ++i)
        {
            if((i+1) % 3 == 0)
            {
                ans[i] = "Fizz";
                flag = true;
            }
            if((i+1) % 5 == 0)
            {
                if(flag)
                {
                    ans[i] = "FizzBuzz";
                }else{
                    ans[i] = "Buzz";
                    flag = true;
                }
            }
            if(!flag)
            {
                ans[i] = std::to_string(i+1);
            }
            flag = false;
        }
        return ans;
    }
};
