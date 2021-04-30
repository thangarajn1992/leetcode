vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2,-1);
    int start = 0;
    int end = nums.size() - 1;
    if(nums.size())
    {
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target)
            {
                res[0] = mid;
                res[1] = mid;
                for(int i = 0; mid - i >= 0 || mid + i < nums.size(); i++)
                {
                    if(mid-i >= 0 && nums[mid-i] == target)
                        res[0] = mid-i;
                    if(mid + i < nums.size() && nums[mid+i] == target)
                        res[1] = mid+i;
                }
                break;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
                continue;
            }
            else
            {
                start = mid + 1;
                continue;
            }
        }
    }
    return res;
}
