class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> c;
        for(int i=0;i<n;i++){
            while(!c.empty() && temperatures[i]>temperatures[c.top()]){
                int idx=c.top();
                ans[idx]=i-idx;
                c.pop();
            }
            c.push(i);
        }
        return ans;
    }
};
