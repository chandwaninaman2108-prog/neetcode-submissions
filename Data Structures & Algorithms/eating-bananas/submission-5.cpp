class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int st=1,end=piles[n-1],ans=0;// Varying values of k
        while(st<=end){
            int mid=st+(end-st)/2;
            int hours=0;
            for(int i=0;i<n;i++){
                if(mid<piles[i]){
                    hours+=piles[i]%mid==0? piles[i]/mid:(piles[i]/mid)+1;
                }
                else{hours+=1;}
            }
            if(hours<=h){ans=mid; end=mid-1;}else{st=mid+1;}
        }
        return ans;
    }
};
