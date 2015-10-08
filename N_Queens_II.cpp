#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        int count = 0;
        recurNQueens(board, 0, n, count);
        return count;

    }

    void recurNQueens(vector<string>& board, int cur, int n, int& count){
    	if(cur >= n){
    		++count;
    		return;
    	}

    	for(int i = 0; i < n; ++i){
    		board[cur][i] = 'Q';
    		//check column
    		bool check_flag = true;
    		for(int j = 0; j < cur; ++j){
    			if(board[j][i] == 'Q'){
    				check_flag = false;
    				break;
    			}
    		}

    		//check 45
    		if(check_flag){
				int x = cur - 1;
				int y = i - 1;
				while(x >= 0 && y >= 0){
					if(board[x][y] == 'Q'){
						check_flag = false;
						break;
					}
					--x;
					--y;
				}
    		}

    		//check 135
    		if(check_flag){
	    		int x = cur - 1;
	    		int y = i + 1;
	    		while(x >= 0 && y <= n-1){
	    		    if(board[x][y] == 'Q'){
	    				check_flag = false;
	    				break;
	    			}
	    			--x;
	    			++y;	
	    		}
    		}

    		if(check_flag){
    			recurNQueens(board,cur+1,n,count);
    		}

    		board[cur][i] = '.';
    	}
    }
};