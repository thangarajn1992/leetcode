map<int,int> m;
vector<int> twoSum(vector<int>& nums, int target) {
   for(int i = 0; i < nums.size(); i++)
   {
       if(m.size())
       {
           if(m.count(nums[i]))
             return {m.at(nums[i]), i};     
       }
       m.insert(pair<int,int>(target-nums[i], i));
   }
  return {};
}
