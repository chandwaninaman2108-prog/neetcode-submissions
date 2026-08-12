class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n,0);
        stack<int> c;
        for(int i=0;i<n;i++){
            while(!c.empty() && temp[i]>temp[c.top()]){// c.top() is an index and I mistakeenly wrote c.top() in place of temp[c.top()] while comparing.
                int idx=c.top();
                ans[idx]=i-idx;
                c.pop();
            }
            c.push(i);//We need to create a stack of indices in order but mistakenly I wrote s[i] in place of i inside push() function
        }
        return ans;
    }
};
