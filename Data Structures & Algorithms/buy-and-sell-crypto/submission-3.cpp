class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int lp=0,rp=1,maxprof=0;
        while(lp<rp && rp<n){
            if(prices[lp]>prices[rp]){lp=rp; rp++;}
            else{maxprof=max(maxprof,prices[rp]-prices[lp]); rp++;}
        }
        return maxprof;
    }
};
