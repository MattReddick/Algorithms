/*

You are the boss of ACM (Air Conditioned Minions), an upstanding company with a single goal of world domination.

The company has 𝑁 minions. Each minion works evilly from early morning until evening inside a super secret bunker
in Helsinki. After much deliberation, you decided to move your headquarters to Singapore. However, unlike Helsinki,
Singapore is very hot, so the entire complex must be air conditioned. With strenuous working hours (under minimum wage too),
it is imperative that all your minions work under optimal work condition. In particular, all minions must like the 
temperatures of the rooms they are in.

You are planning to construct several rooms in your new hideout, and assign your minions there. You fix the temperature
of each room to any value you want (different rooms may have different temperatures). After you fix the temperatures,
you will assign each of your minions to these rooms (a room can hold any number of minions). You want all minions to like
the temperatures of their assigned rooms. Each minion likes an interval of temperature, and these preferences will be given to you.

Air conditioners are very expensive to maintain. Thus, you want to construct as few rooms as possible. 
What is the minimum number of rooms you need to set up such that it would be possible to assign minions to rooms as discussed earlier?

Input
The first line contains a non-negative integer 2≤𝑁≤100, giving the number of minions in your company. The next 𝑁 lines each describe the temperature preferences of all your minions. The 𝑖-th line consists of two single space separated integers 𝐿 and 𝑈 (1≤𝐿≤𝑈≤2𝑁), which denotes that the 𝑖-th minion likes any temperature between 𝐿 and 𝑈, inclusively.

Output
Print an integer denoting the minimum number of rooms you need to construct.

*/

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <vector>

using namespace std;
 
int main() {

    std::ios_base::sync_with_stdio(false);
    vector<tuple<int,int>> minions;
    int N, L, U;
    cin >> N;
   
    for(int i =0; i < N; i++){
      cin >> L;
      cin >> U;
      minions.push_back(make_tuple(L,U));
    }

    int rooms = 1;
    sort(minions.begin(),minions.end());
    int marker = get<1>(minions[0]);

    for(int i = 1; i < N; i++){
      if(get<0>(minions[i]) > marker){
        rooms++;
        marker = get<1>(minions[i]);
      }else{
        if(get<1>(minions[i]) < marker){
          marker = get<1>(minions[i]);
        }
      }
    }

    cout << rooms;
}
