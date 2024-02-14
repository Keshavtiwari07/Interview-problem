class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int result = 0;
        int majoritys = 0;

        for (int n : nums) {
            hash[n] = 1 + hash[n];
            if (hash[n] > majoritys) {
                result = n;
                majoritys = hash[n];
            }
        }

        return result;        
    }
};