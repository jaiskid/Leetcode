int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
       for(int i=0;i+1<points.size();i++){
           ans+=max(abs(points[i+1][1]-points[i][1]),abs(points[i+1][0]-points[i][0]));
       } 
        return ans;
}