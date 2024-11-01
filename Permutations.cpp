class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > res;

        auto f = [&](auto && self, int indx) -> void {
                    if (indx == n) { 
                        res.emplace_back(nums);
                        return;
                    }
                    for (int i = indx; i < n; i++) { 
                        swap(nums[indx], nums[i]);     
                        self(self, indx + 1);         
                        swap(nums[indx], nums[i]);     
                    }
            };

        f(f, 0);
        return res;

    }
};
