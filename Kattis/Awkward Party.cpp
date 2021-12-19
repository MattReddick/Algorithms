/*

Martin has invited everyone he knows to celebrate his 535th birthday, and 
a whopping 𝑛 people from all over the world have accepted the invitation.
When deciding the seating arrangement, Martin’s mother Margarethe have decided 
that all the guests should be seated with maximum awkwardness; this is to ensure 
that nobody has anything meaningful to discuss during dinner, and everyone would 
instead silently enjoy her rather tasty coriander soup (as the saying goes; “when 
the food is good, conversation dies”).

Margarethe knows that awkwardness is maximized if the guests are seated in a long 
row along a single table, in such a way that nobody sits next to someone speaking 
the same language as themselves. Better yet, she has defined the awkwardness level 
of a seating arrangement to be the minimum number of seats separating any two guests 
speaking the same language. If no two people speak the same language, the awkwardness
level is defined to be 𝑛 (the number of guests). Two seats next to each other are said
to be separated by 1.Given the languages spoken in a proposed seating arrangement, can 
you help Margarethe determine the awkwardness level?

Input
The first line contains an integer 𝑛 (1≤𝑛≤100000) denoting the number of guests. On the
second line follows 𝑛 integers, the 𝑖’th of which 𝑥𝑖 (0≤𝑥𝑖≤109) indicating the language 
spoken by the guest seated at position 𝑖 in the proposed arrangement (each guest speaks 
exactly one language).

Output
A single integer, the awkwardness level of the proposed seating arrangement.

Sample Input 1	Sample Output 1
4
1 2 3 1         3

Sample Input 2	Sample Output 2
3
1 2 3           3
*/

#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

class Hash 
{ 
    long long bucket; 
public: 
    long long smallestGap;
    list<long long> *table;
    Hash(long long V); 
    void findItem(long long x, long long y);
    long long getSmallest();
    ~Hash();
}; 
  
Hash::Hash(long long b) 
{ 
    bucket = b; 
    table = new list<long long>[2*bucket];
    smallestGap = bucket;
} 

long long Hash::getSmallest(){
    return smallestGap; 
}

Hash::~Hash(){
    delete[] table;
}

  
void Hash::findItem(long long value, long long loc) 
{ 
  int size = table[value].size();
  
  if(size  == 0){
    table[value].push_back(loc);
  }else{
    
        if (loc - *(table[value].begin())  < smallestGap) {
        smallestGap = (loc - *(table[value].begin()));
    }
    
    table[value].push_back(loc);
    table[value].pop_front();
   
  }
} 
    
 
int main() {
    std::ios_base::sync_with_stdio(false);
    long long n, curr, x;
    int counter = 0;
    vector<long long> input;
    long long tiny = 100001;
   
    while(cin >>  x){
        n = x;
    if( n == 0){
       n = n*2;
       
    }else{
            Hash* languages = new Hash(n);
            for(long long i = 0; i < n; i++){
                    cin >> curr;
                    languages->findItem(curr,i);
                
            }
        if(languages->getSmallest() < tiny){
            tiny = languages->getSmallest();
        }
    }
        
    }
    if(tiny == 100001){
    tiny = 0;
    }
    cout << tiny  << endl;
   
}
