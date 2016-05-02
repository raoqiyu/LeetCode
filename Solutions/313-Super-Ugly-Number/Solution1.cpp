class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Math , index
        // ugly[i] : the i-th ugly number
        // idx[i]  : position of primes[i]'s ugly number which(prime[i] not consumed) in the ugly
        vector<int> ugly(n,0), idx(primes.size(),0);
        ugly[0]= 1;
        for(int i = 1; i < n; i++){
            int min_ugly = INT_MAX;
            int min_idx = 0;
            for(int j = 0; j < primes.size(); j++){
                int temp = ugly[idx[j]] * primes[j];
                if(min_ugly > temp){
                    min_ugly = temp;
                    min_idx = j;
                }else if(min_ugly == temp)
                    idx[j]++; // if temp = min_ugly, it is same as primes[j] consumed a ugly number
            }
            ugly[i] = min_ugly;
            idx[min_idx]++;  // primes[min_idx] consumed a ugly number, so update its idx
        }
        return ugly[n-1];
    }
};
