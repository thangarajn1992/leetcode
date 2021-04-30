int removeDuplicates(vector<int>& nums) {
    int unique = 0;
    if(nums.size() == 0)
        return 0;
    for(int i = 1; i < nums.size() ; i++)
    {
        if(nums[i] != nums[unique])
            nums[++unique] = nums[i];
    }
    return unique+1;
}
