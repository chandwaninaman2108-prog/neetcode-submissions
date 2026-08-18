class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& smaller=nums1.size()<=nums2.size()? nums1:nums2;// <= or >= is important as arrays can also have equal sizes;
        vector<int>& larger=nums1.size()>nums2.size()? nums1:nums2;
        int st=0,end=smaller.size(),totalsize=nums1.size()+nums2.size();
        while(st<=end){
            int partX=(st+end)/2;
            int partY= (totalsize+1)/2 - partX;
            int l1=partX==0?INT_MIN:smaller[partX-1],r1=partX==smaller.size()?INT_MAX:smaller[partX];
            int l2=partY==0?INT_MIN:larger[partY-1],r2=partY==larger.size()?INT_MAX:larger[partY];
            if(l1<=r2 && l2<=r1){
                if(totalsize%2==0){
                    return ((double)max(l1,l2)+(double)min(r1,r2))/2;
                }
                else{
                    return max(l1,l2);
                }
            }
            else{
                if(l1>r2){end=partX-1;}
                else{st=partX+1;}
            }
        }
        return 0;
    }
};
