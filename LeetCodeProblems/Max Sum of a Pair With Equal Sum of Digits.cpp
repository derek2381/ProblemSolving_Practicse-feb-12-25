// Problem Link
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/


// Source Code

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> mp;

        for(int i : nums){
            int temp = i;
            int sum = 0;
            while(temp > 0){
                sum += temp%10;
                temp /= 10;
            }
            mp[sum].push_back(i);
        }

        int res = -1;

        for(auto it : mp){
            sort(it.second.begin(), it.second.end());

            if(it.second.size() >= 2){
                int n = it.second.size();

                int val = it.second[n-1] + it.second[n-2];

                if(val > res){
                    res = val;
                }
            }
        }

        return res;
    }
};