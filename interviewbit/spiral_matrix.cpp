vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int row = A.size();
	int col = A[0].size();
	
	int t = 0, b = row - 1, l = 0, r = col - 1;
	int dir = 0, i;
	while (t <= b && l <= r) {
	    if (dir == 0) {
	        // traverse left to right
	        for (i = l; i <= r; i++) {
	            result.push_back(A[t][i]);
	        }
	        t++;
	    } else if (dir == 1) {
	        // traverse top to bottom
	        for (i = t; i <= b; i++) {
	            result.push_back(A[i][r]);
	        }
	        r--;
	    } else if (dir == 2) {
	        // traverse right to left
	        for (i = r; i >= l; i--) {
	            result.push_back(A[b][i]);
	        }
	        b--;
	    } else if (dir == 3) {
	        // traverse bottom to top
	        for (i = b; i >= t; i--) {
	            result.push_back(A[i][l]);
	        }
	        l++;
	    }
	    dir = (dir + 1) % 4;
	}
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
