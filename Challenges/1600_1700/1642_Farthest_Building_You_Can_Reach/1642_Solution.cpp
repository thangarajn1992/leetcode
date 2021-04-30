priority_queue<int> q;
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
   int i = 0;
   for( i = 0; i < heights.size() - 1 ; i++){
      if(heights[i] >= heights[i+1])
         continue;
      int diff = heights[i+1] - heights[i];
      if(diff <= bricks)
      {
         bricks -= diff;
         q.push(diff);
      }
      else if(ladders)
      {
         if(q.size())
         {
            int max_b = q.top();
            if(max_b > diff) // If earlier max is less than this, change ladder
            {                            
                q.pop();
                bricks += max_b;
                bricks -= diff;
                q.push(diff);
            }
         }
         ladders--;
      }
      else
         break;
    }
    return i;
}  
