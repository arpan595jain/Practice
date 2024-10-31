class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,l=nums.size();
        int break_point=INT_MIN;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                break_point=i-1;
                break;
            }
        }
        if(break_point==INT_MIN)
        {
        sort(nums.begin(),nums.end());
        return;
        }
        int ele=nums[break_point];
        int maxmin=INT_MAX;
        int index;
        for(int i=break_point;i<l;i++)
        {
        if(nums[i]>ele)
        {
        maxmin=min(maxmin,nums[i]);
        index=i;
        }
        }
    swap(nums[break_point],nums[index]);
    vector<int>temp;
    for(int i=break_point+1;i<l;i++)
    {
        temp.push_back(nums[i]);
    }
    sort(temp.begin(),temp.end());
    int x=0;
    for(int i=break_point+1;i<l;i++)
    {
        nums[i]=temp[x++];
    }
    }
};
