class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int st=1,end=piles[n-1],ans=0;// min_k=1bph,max_k=maxele bph.
        while(st<=end){
            int mid= st+(end-st)/2;
            int hours=0;
            for(int i=0;i<n;i++){
                if(piles[i]>mid){
                    if(piles[i]%mid==0) hours+=piles[i]/mid;
                    else{hours+=piles[i]/mid +1;}
                }else{hours+=1;}
            }
            if(hours<=h){ans=mid; end=mid-1;}
            else{st=mid+1;}
        }
        return ans;
    }
};
