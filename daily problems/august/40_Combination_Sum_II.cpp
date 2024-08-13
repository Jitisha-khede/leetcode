class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combi;
        combination2(res, combi, candidates, target, 0);
        return res;
    }
    void combination2(vector<vector<int>> &res, vector<int> &combi,
                      vector<int> &candidates, int target, int index) {
        if (target == 0) {
            res.push_back(combi);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i];
             ++i) {
            if (i == index || candidates[i] != candidates[i - 1]) {
                combi.push_back(candidates[i]);
                combination2(res, combi, candidates,
                             target - candidates[i], i + 1);
                combi.pop_back();
            }
        }
    }
};