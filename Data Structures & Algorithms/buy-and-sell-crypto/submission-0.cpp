class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 2pointer approach
        int n=prices.size();
        int lp=0,rp=1;
        int maxprof=0;
        while(lp<rp && rp<n){
            if(prices[lp]>prices[rp]){lp=rp; rp++;}
            else{maxprof=max(maxprof,prices[rp]-prices[lp]); rp++;}
        }
        return maxprof;


    }
};
