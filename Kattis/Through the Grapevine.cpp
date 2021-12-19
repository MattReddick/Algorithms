/*

According to Wikipedia, to hear something “through the grapevine” is to learn of something informally and 
unofficially by means of gossip or rumor. In this problem, you are tasked with determining how many people
will hear about a particular rumor “through the grapevine” after a certain number of days.

Rumors are always started by a single person. On any given day, a person who knows the rumor can spread it 
by telling the people that they know. Upon hearing of the rumor, that person must wait until the following 
day before they can begin to spread it themselves. Furthermore, some people are skeptical and will only 
spread the rumor once they’ve heard it from a number of distinct sources. However once a person has heard 
the rumor from enough people, they will always try to spread the rumor to as many people as possible.

Input
The first line will contain three integers: 0<𝑛≤100000, 0<𝑚≤100000, and 0≤𝑑≤10000, 
where 𝑛 is the number of people, 𝑚 is the number of connections, and 𝑑 is the number of days that elapse.

The next 𝑛 lines will each consist of a unique string 𝑠 and an integer 0≤𝑡≤1000 
where 𝑠 is the name of a erson and 𝑡 is their level of skepticism. In other words, 
person 𝑠 must hear the rumor from 𝑡 distinct other people before 𝑠 will begin spreading the rumor.

This is followed by 𝑚 lines each consisting of two strings 𝑢 and 𝑣 which indicates that person 𝑢 and person 𝑣 know each other.
Each of these lines represents a unique pair of persons.

The final line will contain a single string 𝑟, the name of the person that the rumor originates from. 
Note that 𝑟 is the only person with skepticism 𝑡=0. All strings are between 1 and 20 characters long and 
consists only of English lowercase or uppercase letters and digits.
*/

#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include <unordered_set>
using namespace std;
const int maxn = 100000;

int skepticism[maxn];
vector<int> connections[maxn];
bool hasHeard[maxn];

int main(){
    int n,m,d;
    cin >> n >> m >> d;
    map<string,int> indexes;

    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        indexes[name] = i;
        cin >> skepticism[i];
    }

    for(int i = 0; i < m; i++){
        string p1, p2;
        cin >> p1 >> p2;
        connections[indexes[p1]].push_back(indexes[p2]);
        connections[indexes[p2]].push_back(indexes[p1]);

    }

    string r;
    cin >> r;
    int start = indexes[r];

    hasHeard[start] = true;
    vector<int> convinced;
    convinced.push_back(start);
    int totalHeard = 0;

    for(int days = 0; days < d; days++){
        vector<int> spreadTomorrow;
        for( auto i : convinced){
            for(int j : connections[i]){
                if(hasHeard[j] || skepticism[j] != 0){
                    skepticism[j]--;
                }
                if(!hasHeard[j]){
                    hasHeard[j] = true;
                    totalHeard++;

                }
                if(skepticism[j] == 0){
                    spreadTomorrow.push_back(j);
                }
            }
        }
        convinced = spreadTomorrow;
    }
    cout << totalHeard << endl;

}
