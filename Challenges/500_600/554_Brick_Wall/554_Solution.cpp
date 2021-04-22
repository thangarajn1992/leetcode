int leastBricks(vector<vector<int>>& wall) {
   int size = wall.size();
   unordered_map<int,int> count;
   int temp = 0;
   int maxi = 0;
   for(int i = 0; i < size; i++)
   {
       for(int j = 0; j < wall[i].size() - 1; j++)
       {
           temp += wall[i][j];
           count[temp]++;
           maxi = max(maxi, count[temp]);
       }
       temp = 0;
    }
    return size - maxi;
}
