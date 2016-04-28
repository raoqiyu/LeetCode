class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // State machine
        // Reference : https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
        // Three state : state0, state1, state2;  start at state0
        // at state0, if buy  go to state1, if do nothing stay at state0
        // at state1, if sell go to state2, if do nothing stay at state1
        // at state2, do nothing and go to state0 
        
        // once you buy  you must from state0 to state1
        // once you sell you must from state1 to state2
        // once you at state2, you cannot buy or sell because of "cooldown", you just goto state0
        
        // state0 = max(last_state0, last_state2)
        // state1 = max(last_state1, last_state0-prices[i])
        // state2 = last_state1+prices[i]
        if(prices.size() == 0)
            return 0;
            
        int last_state2 = -1;
        
        int state0 = 0;             // initial state
        int state1 = -prices[0];    // first buy
        int state2 = 0;             // initial state
        
        for(int i = 1; i < prices.size(); i++){
            int last_state2 = state2;
            state2 = state1 + prices[i];    
            state1 = max(state1, state0-prices[i]);
            state0 = max(state0, last_state2);
        }
        
        return max(state0, state2);
    }
};
