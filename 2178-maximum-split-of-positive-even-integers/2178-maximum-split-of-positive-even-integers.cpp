class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum%2!=0) return ans;
        long long i=2;
        long long currsum=0;
        while((currsum+i)<=finalSum)
        {
            ans.push_back(i);
            currsum+=i;
            i+=2;
        }
        ans[ans.size()-1]+=finalSum-currsum;
        return ans;
    }
};