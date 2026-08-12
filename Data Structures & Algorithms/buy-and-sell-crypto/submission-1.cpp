class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //forward moving two pointer approach
        int n=prices.size();
        int lp=0,rp=1,maxprofit=0;
        while(lp<rp && rp<n){
            if(prices[lp]>prices[rp]){lp=rp; rp++;}
            else{maxprofit=max(maxprofit,prices[rp]-prices[lp]); rp++;}
        }
        return maxprofit;

    }
};
