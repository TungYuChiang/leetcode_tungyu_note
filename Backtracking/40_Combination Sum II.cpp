class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        dfs(candidates, target, 0, 0, res, curr);
        return res;
    }

    void dfs(vector<int> cands, int target, int start, int sum, vector<vector<int>>& res, vector<int>& curr){
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < cands.size(); i++) {
            if (i > start && cands[i] == cands[i - 1]){
                continue;
            }
            curr.push_back(cands[i]);
            dfs(cands, target, i + 1, sum + cands[i], res, curr);
            curr.pop_back();
        }
    }
};