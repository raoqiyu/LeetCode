class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        // cnt = 1 for number 2, because we do not count it next
        int cnt = 1;
        bool* isprimes = new bool[n];
        for(int i = 0; i < n; i++)
            isprimes[i] = true;
        
        // skip all even number
        for(int i = 3; i*i <= n; i+=2){
            if(isprimes[i] )
                // i is a odd number so, i*i + i, i*i + 3i... are even number, so we skip these number by doing j += 2*i
                for(int j = i*i; j < n; j+=2*i)
                    isprimes[j] = false;
        }
        
        // skip all even number
        for(int i = 3; i < n; i+=2){
            if(isprimes[i] == true)
                cnt++;
        }   
        delete isprimes;
        return cnt;
    }
};
