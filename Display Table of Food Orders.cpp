class Solution 
{
public:
    vector<vector<string>> displayTable(vector<vector<string>>& nums) 
    {
         map<int,map<string,int>>mp;
         set<string>st;
         int n=nums.size();
         for(int i=0;i<n;i++)
         {
        st.insert(nums[i][2]);
        mp[stoi(nums[i][1])][nums[i][2]]++;
         }
         vector<string>v(st.begin(),st.end());
         vector<vector<string>>ans;
         vector<string>v1;
         v1.push_back("Table");
         for(int i=0;i<v.size();i++)
             v1.push_back(v[i]);
         ans.push_back(v1);
         for(auto i=mp.begin();i!=mp.end();i++)
         {
             vector<string>v2;
             v2.push_back(to_string(i->first));
             for(int j=0;j<v.size();j++)
                 v2.push_back(to_string(i->second[v[j]]));
             ans.push_back(v2);
         }
         return ans; 
    }
};
