class Solution {
public:
    // int countPairs(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     int ct=0;
    //     for(int i=0;i<n-1;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i]==nums[j] and (i*j)%k==0) ct++;
    //         }
    //     }
    //     return ct;
    // }
     int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numToIndex;
        int result=0;
        for (int i=0;i<nums.size(); i++){
		// for each index i, match it with previous index that has the same number
            if (numToIndex.find(nums[i])!=numToIndex.end()){ 
                for (int pos: numToIndex[nums[i]]){
                    if ( (pos*i)%k == 0){
                        result++;
                    }
                }
                numToIndex[nums[i]].push_back(i);
            }else{
                numToIndex[nums[i]]={i};            
            }
        }
        return result;
    }
};