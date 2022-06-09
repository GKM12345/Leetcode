class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int si=0,ei=numbers.size()-1;
        vector<int> ans;
        while(si<ei)
        {
            if(numbers[si]+numbers[ei]==target)
            {
                ans.push_back(si+1);
                ans.push_back(ei+1);
                break;
            }
            else if(numbers[si]+numbers[ei]>target)
            {
                ei--;
            }
            else
            {
                si++;
            }
        }
        return ans;
        
    }
};