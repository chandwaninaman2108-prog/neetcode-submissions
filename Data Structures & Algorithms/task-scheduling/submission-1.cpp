class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        1. Find frequency of each element.
        2. After each operation determine the max. frequency
        3. Maintain cooldown period
        */
        // I will be using the gap formula instead of pq. Consider this as a math problem
        vector<int> count(26,0);
        int maxfreq=INT_MIN;
        for(char c:tasks){
            count[c-'A']++;
            maxfreq=max(maxfreq,count[c-'A']);
        }
        int maxcount=0;
        for(int a:count){
            if(a==maxfreq){maxcount++;}
        }
        int intervals=(maxfreq-1)*(n+1)+maxcount;
        int size=tasks.size();
        return max(size,intervals);


    }
};
