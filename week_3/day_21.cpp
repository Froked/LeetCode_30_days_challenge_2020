/**

(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

 

 

Example 1:



Input: mat = [[0,0],[1,1]]
Output: 0
Example 2:



Input: mat = [[0,0],[0,1]]
Output: 1
Example 3:



Input: mat = [[0,0],[0,0]]
Output: -1
Example 4:



Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.

**/


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

// solution 1: binary search: O(NlogM)
// expected query: 665

class Solution {
public:
    int n, m;
    int f(int M, BinaryMatrix &binaryMatrix)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += binaryMatrix.get(i, M);
        }
        return cnt;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dim = binaryMatrix.dimensions();
        n = dim[0];
        m = dim[1];
        int L = 0;
        int R = m;
        int M;
        while(L < R)
        {
            M = L + (R - L)/2;
            if(f(M, binaryMatrix) == 0) L = M + 1;
            else R = M;
        }
        if(L == m) L = -1;
        return L;
    }
};

// solution 2: traversing grid: O(N + M)
// expected query: 200

class Solution {
public:
    int n, m;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dim = binaryMatrix.dimensions();
        n = dim[0];
        m = dim[1];
        int max_till_now = 0;
        int U = 0;
        int D = n - 1;
        
        while(U <= D)
        {
            int v = binaryMatrix.get(U, m - max_till_now - 1);
            if(v == 1) max_till_now++;
            else U++;
            if(max_till_now == m) return 0;
        }
        return m - max_till_now == m ? -1 : m - max_till_now;
        
    }
};

// solution 3: randomized row selection: Θ(log2(N) * log2(M))
// expected query: 49

class Solution {
public:
    int n, m;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dim = binaryMatrix.dimensions();
        n = dim[0];
        m = dim[1];
        int max_till_now = 0;
        int U = 0;
        int D = n - 1;
        
        vector<int>rows(n);
        iota(rows.begin(), rows.end(), 0);
        random_shuffle(rows.begin(), rows.end());
        
        while(U <= D)
        {
            if(max_till_now == m) return 0;
            int v = binaryMatrix.get(rows[U], m - max_till_now - 1);
            if(v == 1) max_till_now++;
            else U++;
        }
        return m - max_till_now == m ? -1 : m - max_till_now;
        
    }
};