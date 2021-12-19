/*

Digits 4 and 7 are lucky, while all others are unlucky. An integer is lucky
if it contains only lucky digits in decimal notation. We would like to know 
the 𝐾-th lucky positive integer.

Input
The first and only line of input contains a positive integer 𝐾 (1≤𝐾≤109).

Output
The first and only line of output must contain the 𝐾-th lucky positive integer.

*/

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <vector>
#include <tgmath.h>
#include <stdio.h>
using namespace std;

void getLuckyNum(int K){
    if(K == 1){
      cout << "4" << endl;
      return;
    }else if(K == 2){
      cout << "7" << endl;
      return;
    }

    std::bitset<32> Binary(K+1);
    string solution = Binary.to_string('4','7');
    deque<char> queue(solution.begin(),solution.end());
    
    while(queue.size() > 1 && queue.front() == '4'){
      queue.pop_front();
    }
    queue.pop_front();

    for(auto j: queue){
      cout << j;
    }
}
 
int main() {
    int K;
    cin >> K;
    
    getLuckyNum(K);
}
