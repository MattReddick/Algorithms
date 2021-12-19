/*

Having discolored his white socks in a rather beige shade (as seen on the picture), Luktas Svettocek realised
he can’t just throw all his laundry into one machine and expect it to retain its original colors. However, he
is also too lazy to do his laundry in several rounds. He would much rather buy more laundry machines!

Each of Luktas’ socks have a color 𝐷𝑖 which has a number between 0 and 109 assigned to it. After some 
experimentation, he found that he could wash any socks with a maximum absolute color difference of 𝐾 in the 
same machine without any discoloring. The color difference of two socks 𝑖 and 𝑗 is |𝐷𝑖−𝐷𝑗|.

Luktas now needs to know how many washing machines he needs to wash his 𝑆 socks, given that each machine can 
take at most 𝐶 socks a time.

Input:
The first line consists of three integers 1≤𝑆,𝐶≤105 and 0≤𝐾≤109, the number of socks, the capacity of a 
laundry machine and the maximum color difference, respectively. Then follow one line with 𝑆 integers; 
these are the color values 𝐷𝑖 of every sock.

Output:
Output a single integer; the number of machines Luktas needs to wash all his socks.

*/

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <vector>

using namespace std;
 
int main() {

    std::ios_base::sync_with_stdio(false);
    vector<int> socks;
    int S, C, K, D;
    cin >> S >> C >> K;

    for(int i = 0; i < S; i++){
      cin >> D;
      socks.push_back(D);
    }

    sort(socks.begin(),socks.end());
    int machines = 0;

    for(int i = 0; i < S; i+=0){
      for(int j = 1; j <= C; j++){
        if(i + j >= S || j == C || socks[i + j] - socks[i] > K){
          machines++;
          i += j;
          break;
        }
      }
    }

    cout << machines;
   
    
}
