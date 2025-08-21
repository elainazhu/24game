class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }

private:
    static constexpr double TARGET = 24.0;
    static constexpr double EPS = 1e-6;

    bool dfs(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - TARGET) < EPS;
        }

        // Try all unordered pairs (i, j), i < j
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                vector<double> next;
                next.reserve(nums.size() - 1);

                // put all remaining numbers except i and j
                for (int k = 0; k < (int)nums.size(); ++k) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // To reduce duplicates, for + and * (commutative), generate once
                // but it’s fine performance‑wise to try all; still we’ll prune a bit.
                vector<double> candidates = {
                    a + b,
                    a - b,
                    b - a,
                    a * b
                };
                if (fabs(b) > EPS) candidates.push_back(a / b);
                if (fabs(a) > EPS) candidates.push_back(b / a);

                for (double val : candidates) {
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
