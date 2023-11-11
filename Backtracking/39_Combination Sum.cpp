class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        help(candidates, 0, target, res, curr);
        return res;
    }
    void help(vector<int>& cand, int i, int target, vector<vector<int>>& res, vector<int>& curr) {
        if (i >= cand.size() || target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        curr.push_back(cand[i]);

        help(cand, i, target - cand[i], res, curr);

        curr.pop_back();

        help(cand, i + 1, target, res, curr);

    }
    
};