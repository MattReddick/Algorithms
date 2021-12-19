/*

A binary search tree is a tree in which every node has at most two children nodes (a left and a right child).
Each node has an integer written inside it. If the number 𝑋 is written inside a node, then the numbers in its
left subtree are less than 𝑋 and the numbers in its right subtree are greater than X. You will be given a 
sequence of integers between 1 and 𝑁 (inclusive) such that each number appears in the sequence exactly once. 
You are to create a binary search tree from the sequence, putting the first number in the root node and 
inserting every other number in order.

When inserting a new number 𝑌 in a tree, you first traverse the tree as if you were searching for 𝑌. When you
arrive at a node 𝑍 such that you can’t continue searching for 𝑌, you put 𝑌 as a left or right son of 𝑍 depending
on if 𝑍>𝑌 or 𝑍<𝑌, so that after the insertion the tree will still be a binary search tree. After the insertion
you add the depth of 𝑌 to a counter 𝐶 and print the value of 𝐶. The counter 𝐶 is set to 0 in the beginning.

Input
The first line contains the integer 𝑁 (1≤𝑁≤300000), the length of the sequence.
The remaining 𝑁 lines contain the numbers in the sequence, integers in the interval [1,𝑁]. 
The numbers will be distinct.

Output
Output 𝑁 integers each on its own line, the values of the counter 𝐶 after each number is inserted into the tree.

Sample Input 1	Sample Output 1
4               0
1               1
2               3
3               6

Sample Input 2	Sample Output 2
5               0
3               1
2               2
4               4
1               6
5

*/

#include<iostream>
#include<vector>
#include <string>
using namespace std;
const int maxn = 300000;

int max(int a, int b)
{
    if(a>b){
      return a;
    }
    return b;
}

int main() {
      int n,key;
      long long z = 0;
      string var;
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      getline(cin,var);
      n = stoi(var);
      int prev[maxn+1], next[maxn+1];
      int input[maxn+1], M[maxn+1];
      int V[maxn+1], depth[n+1];

      for(int i = 1; i < n+1; i++){
        getline(cin,var);
        input[i] = stoi(var);
      }
      
      for(int i = 1; i < n+1; i++){
        prev[i] = i-1;
        next[i] = i+1;
      }
      
      prev[1] = 0;
      next[n] = 0;
      depth[0] = -1;

      for(int i = n; i > 0; i--){
        
        M[input[i]] = prev[input[i]];
        
        V[input[i]] = next[input[i]];
        
        next[prev[input[i]]] =next[input[i]];
        
        prev[next[input[i]]] =prev[input[i]]; 
        
      }
      
      for(int i = 1; i < n+1; i++){
        depth[input[i]] = 1 + max(depth[M[input[i]]],depth[V[input[i]]]);
        z += depth[input[i]];
        cout << z << '\n';
      }
      
      return 0;
}
