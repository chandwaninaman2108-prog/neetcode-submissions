class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> pospeed(n);
        stack<int> c;
        vector<double> time(n);
        for(int i=0;i<n;i++){
            pospeed[i]={position[i],speed[i]};
        }
        sort(pospeed.begin(),pospeed.end());
        for(int i=0;i<n;i++){
            time[i]=(double)(target-pospeed[i].first)/pospeed[i].second;
        }
        int ct=n;
        for(int i=n-1;i>=0;i--){
            if(!c.empty() && time[i]<=time[c.top()]){
                ct--;
            }
            else{c.push(i);}
        }
        return ct;
    }
};
