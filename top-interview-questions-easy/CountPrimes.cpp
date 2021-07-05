// Simple solution but it use more time
//

class Solution {
public:
    bool isPrime(int n)
    {
        if(n == 1) return false;
        if(n <=3 ) return true;

        if(n%2 ==0 || n%3==0) return false;

        for(int i=5 ; i<(n/2);i+=6)
        {
            if(n%i == 0 || n%(i+2) == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        if(n < 3) return 0;
        if(n == 3) return 1;
        if(n == 4) return 2;

        int count = 2;
        --n;

        while(n > 4)
        {
            if(isPrime(n))
            {
                ++count;
                --n;
            }
            --n;
        }
        return count;
    }
};

//correct Solution
//

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        bool *prime = new bool[n];
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i < n; i++) {
            prime[i] = true;
        }
        //check all numbers
        for(int i = 2; i*i<n;i++)
        {
            if(!prime[i]) continue;
            // check all sq numbers like if i =2 then 4,6,8...
            // if i =3 then 9, 12, 15, 18...
            for(int j = i*i; j<n; j+=i)
            {
                prime[j] = false;
            }
        }
        for(int i=2; i<n;++i)
        {
            if(prime[i]) ++count;
        }
        return count;
    }
};
