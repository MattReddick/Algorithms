/*

A long art gallery has 2𝑁 rooms. The gallery is laid out as 𝑁 rows of 2 rooms side-by-side. 
Doors connect all adjacent rooms (north-south and east-west, but not diagonally). The curator
has been told that she must close off 𝑘 of the rooms because of staffing cuts. Visitors must 
be able to enter using at least one of the two rooms at one end of the gallery, proceed through
the gallery, and exit from at least one of the two rooms at the other end. Therefore, the 
curator must not close off any two rooms that would block passage through the gallery. That is,
the curator may not block off two rooms in the same row or two rooms in adjacent rows that touch 
diagonally. Furthermore, she has determined how much value each room has to the general public,
and now she wants to close off those 𝑘 rooms that leave the most value available to the public,
without blocking passage through the gallery.

Input
Input will consist of multiple problem instances (galleries). Each problem instance will begin 
with a line containing two integers 𝑁 and 𝑘, where 3≤𝑁≤200 gives the number of rows, and 0≤𝑘≤𝑁 
gives the number of rooms that must be closed off. This is followed by 𝑁 rows of two integers, 
giving the values of the two rooms in that row. Each room’s value 𝑣 satisfies 0≤𝑣≤100. A line 
containing 0 0 will follow the last gallery.

Output
For each gallery, output the amount of value that the general public may optimally receive, one line per gallery.

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int maxA(int arr[], int size){
  int m = arr[0];
  for(int i = 1; i < size;i++){
    if (arr[i] > m){
      m = arr[i];
    }
  }
  return m;
}

void helper(int N, int K){
  int rooms[N][2];
  int V;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 2; j++){
        cin >> V;
        rooms[i][j] = V;
    }
  }

  //Row-Solve: RS[i][j][k]: Maximum value for row I, given a blocked J and a blocked K from the previous row. K Values: 0 = open, 1 = left block, 2 = right block

  int RS[N][K+1][3];

  for(int i = 0; i < N; i++){
    for(int j = 0; j <= K; j++){
        RS[i][j][0] = -1;
        RS[i][j][1] = -1;
        RS[i][j][2] = -1;

    }
  }

  //Instantiate the first row of Row-Solve

  RS[0][0][0] = rooms[0][0] + rooms[0][1];
  if(K > 0){
    RS[0][1][1]= rooms[0][1];
    RS[0][1][2]= rooms[0][0];
  }

  //Traverse through each row of rooms
  for(int i = 1; i < N; i++){

    //Traverse through the amount of blocked rooms
    for(int j = 0; j <= i+1 &&  j<= K; j++){

      //Using both current rooms, build off the previous best answer with the previous blocks
      if(maxA(RS[i-1][j], 3) >= 0){
        RS[i][j][0] = rooms[i][0] + rooms[i][1] + maxA(RS[i-1][j],3);
      }

      //either no rooms are blocked or building off the previous blockages
      if(j > 0 && max(RS[i-1][j-1][1],RS[i-1][j-1][0]) >= 0){
        RS[i][j][1] = rooms[i][1] + max(RS[i-1][j-1][1],RS[i-1][j-1][0]);
      }
      if(j > 0 && max(RS[i-1][j-1][2],RS[i-1][j-1][0]) >= 0){
        RS[i][j][2] = rooms[i][0] + max(RS[i-1][j-1][2],RS[i-1][j-1][0]);
      }
    }
  }

  cout << maxA(RS[N-1][K], 3) << endl;
}

int main() {
  int K,N,V;
  cin >> N;
  cin >> K;

  while((N+K) != 0){
    helper(N,K);
    cin >> N;
    cin >> K;

  }
  
}
