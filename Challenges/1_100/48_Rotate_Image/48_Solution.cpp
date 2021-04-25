void rotate(vector<vector<int>>& matrix) {
   int n = matrix.size();
   if(n == 0 || n == 1)
      return;
   for(int i = 0; i < n; i++)
   {
      for(int j = i+1; j < n; j++)
          swap(matrix[i][j], matrix[j][i]);
      reverse(matrix[i].begin(), matrix[i].end());
   }
}
