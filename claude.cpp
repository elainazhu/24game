class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back(static_cast<double>(card));
        }
        return solve(nums);
    }
    
private:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-9;
        }
        
        // Try all ordered pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    double a = nums[i];
                    double b = nums[j];
                    
                    // Create vector with remaining numbers
                    vector<double> remaining;
                    for (int k = 0; k < nums.size(); k++) {
                        if (k != i && k != j) {
                            remaining.push_back(nums[k]);
                        }
                    }
                    
                    // Try all operations: +, -, *, /
                    vector<double> operations = {a + b, a - b, a * b};
                    if (abs(b) > 1e-9) {  // Avoid division by zero
                        operations.push_back(a / b);
                    }
                    
                    for (double result : operations) {
                        vector<double> nextNums = remaining;
                        nextNums.push_back(result);
                        if (solve(nextNums)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};