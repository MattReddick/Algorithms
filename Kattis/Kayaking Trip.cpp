/*

You are leading a kayaking trip with a mixed group of participants in the Stockholm archipelago, but as you are about 
to begin your final stretch back to the mainland you notice a storm on the horizon. You had better paddle as fast as 
you can to make sure you do not get trapped on one of the islands. Of course, you cannot leave anyone behind, so your 
speed will be determined by the slowest kayak. Time to start thinking; How should you distribute the participants among 
the kayaks to maximize your chance of reaching the mainland safely?

The kayaks are of different types and have different amounts of packing, so some are more easily paddled than others. 
This is captured by a speed factor 𝑐 that you have already figured out for each kayak. The final speed 𝑣 of a kayak, 
however, is also determined by the strengths 𝑠1 and 𝑠2 of the two people in the kayak, by the relation 𝑣=𝑐(𝑠1+𝑠2). 
In your group you have some beginners with a kayaking strength of 𝑠𝑏, a number of normal participants with strength 𝑠𝑛 
and some quite experienced strong kayakers with strength 𝑠𝑒.

Input
The first line of input contains three non-negative integers 𝑏, 𝑛, and 𝑒, denoting the number of beginners, 
normal participants, and experienced kayakers, respectively. The total number of participants, 𝑏+𝑛+𝑒, will be even, 
at least 2, and no more than 100000. This is followed by a line with three integers 𝑠𝑏, 𝑠𝑛, and 𝑠𝑒, giving the strengths
of the corresponding participants (1≤𝑠𝑏<𝑠𝑛<𝑠𝑒≤1000). The third and final line contains 𝑚=𝑏+𝑛+𝑒2 integers 𝑐1,…,𝑐𝑚 (1≤𝑐𝑖≤100000 
for each 𝑖), each giving the speed factor of one kayak.

Output
Output a single integer, the maximum speed that the slowest kayak can get by distributing the participants two in each kayak.

*/

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> participants;
vector<int> strengths;
vector<int> kayaks;
int people;

bool ValidSpeed(int speed){
  vector<int> p = participants;
 
  for(int i = (people/2)-1; i>=0; i--){
    if(p[0] >= 2 && (2*strengths[0]*kayaks[i] >= speed)){ //BB
      p[0] -= 2;
    }else if (p[0] >=1 && p[1] >=1 && kayaks[i]*(strengths[0]+strengths[1]) >= speed){ //BN
      p[0] -= 1;
      p[1] -= 1;
    }else if(2*strengths[1] <= strengths[0]+strengths[2]){ //NN before BE
      if(p[1] >= 2 && 2*strengths[1]*kayaks[i] >= speed){ //NN
        p[1] -= 2;
      }else if(p[0] >=1 && p[2] >=1 && kayaks[i]*(strengths[0]+strengths[2]) >= speed){ //BE
        p[0] -= 1;
        p[2] -= 1;
      }else if(p[1] >=1 && p[2] >=1 && kayaks[i]*(strengths[1]+strengths[2]) >= speed){ //NE
        p[1] -= 1;
        p[2] -= 1;
      }else if(p[2] >= 2 && (2*strengths[2]*kayaks[i] >= speed)){ //EE
        p[2] -= 2;
      }else{
        return false;
      }
    }else{ //BE before NN
      if(p[0] >=1 && p[2] >=1 && kayaks[i]*(strengths[0]+strengths[2]) >= speed){ //BE
        p[0] -= 1;
        p[2] -= 1;
      }else if(p[1] >= 2 && 2*strengths[1]*kayaks[i] >= speed){ //NN
        p[1] -= 2;
      }else if(p[1] >=1 && p[2] >=1 && kayaks[i]*(strengths[1]+strengths[2]) >= speed){ //NE
        p[1] -= 1;
        p[2] -= 1;
      }else if(p[2] >= 2 && (2*strengths[2]*kayaks[i] >= speed)){ //EE
        p[2] -= 2;
      }else{
        return false;
      }
    }
  }
  return true;
}

int BinarySearch(){
  int low = 1;
  int high = 2*kayaks[(people/2)-1]*strengths[2];
  

  while(low < high){
    int mid = (low+high+1)/2;
    if(ValidSpeed(mid)){
      low = mid;
    }else{
      high = mid - 1;
    }
  }
  return low;
}
 
int main() {

    std::ios_base::sync_with_stdio(false);

    int input;
    people = 0;

    for(int i = 0; i < 3; i++){
      cin >> input;
      people+=input;
      participants.push_back(input);
    }
    for(int i = 0; i < 3; i++){
      cin >> input;
      strengths.push_back(input);
    }
    for(int i = 0; i < (people/2); i++){
      cin >> input;
      kayaks.push_back(input);
    }

    sort(kayaks.begin(),kayaks.end());

    cout << BinarySearch();
}
