#include<bits/stdc++.h>
void SortedStack :: sort()
{
   multiset<int> s1;
   while(!s.empty())
   {
       s1.insert(s.top());
       s.pop();
   }
   for(auto it : s1)
   {
       s.push(it);
   }
}