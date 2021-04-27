class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size()/2;i++){
            swap(s[s.size()-i-1],s[i]);
           
        }
    }
};
