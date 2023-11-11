class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(nums, 0, res, curr);

        return res;
    }

    void dfs(vector<int>& nums, int start,  vector<vector<int>>& res, vector<int>& curr) {
        res.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, i + 1, res, curr);
            curr.pop_back();
        }
    }
};