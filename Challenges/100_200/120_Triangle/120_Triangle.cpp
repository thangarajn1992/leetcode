int minimumTotal(vector<vector<int>>& triangle) {
   vector<int> memo(triangle.size()+1, 0);
     
   for(int i = triangle.size() - 1; i >=0; i--)
   {
      for(int j = 0; j < triangle[i].size(); j++)
      memo[j] = triangle[i][j] + min(memo[j], memo[j+1]);
   }
   return memo[0];
}
