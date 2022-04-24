class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	vector<int> ans(size(queries));
	for(int i = 0; i < size(queries); i++){
		int x = queries[i][0], y = queries[i][1], r = queries[i][2];
		for(int j = 0; j < size(points); j++){
			if((x - points[j][0]) * (x - points[j][0]) + (y - points[j][1]) * (y - points[j][1]) <= r * r)    
				ans[i]++;
		}            
	}
	return ans;
}
};