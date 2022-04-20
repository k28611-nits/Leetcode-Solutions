class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        //Initialize the count variable for counting the number of odd valued cells
        int count=0;
		//Initialize a vector of the specified rows and columns consisting of all zeros
        vector<vector<int>> matrix(m, vector<int> (n,0));
		
        for(int i=0; i<indices.size(); i++){
			//First loop through all the cells in the specified row and increment the values
            for(int j=0; j<matrix[indices[i][0]].size(); j++)
                ++matrix[indices[i][0]][j];
            
			//Then loop through all the cells in the specified column and do the same 
            for(int j=0; j<matrix.size(); j++)
                ++matrix[j][indices[i][1]];
        }
        
		//Finally loop through the matrix to count the number of odd valued cells
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]%2)
                    count++;
            }
        }
        
        return count;
    }
};