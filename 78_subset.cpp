class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, curr, res);
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};




