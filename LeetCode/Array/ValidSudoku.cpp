class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    //for row
                    for (int k = 0; k < 9; k++){
                        if(k!=j && board[i][j] == board[i][k]){
                            return false;
                        }
                    }
                    
                    //for col
                    for (int k = 0; k < 9; k++){
                        if(k!=i && board[i][j] == board[k][j]){
                            return false;
                        }
                    }
                    
                    //for 3x3 boxes
                    int k = i/3;
                    int l = j/3;
                    //the above code is the wrong logic
                    
                    for(int h = k*3; h < (k*3)+3;h++){
                        for(int g = l*3; g < (l*3)+3;g++){
                            if(h!=i && g!=j && board[i][j] == board[h][g]){
                                 cout << "i: " << i << "j: " << j;
                                 return false;
                            }
                        }
                    }
                    
                    
                }
            }
        }
        return true;
    }
};
