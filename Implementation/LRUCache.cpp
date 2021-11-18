/**
Implement LRU cache
least recent use 

if cache size is full delete the least recent element in cache.
when element comes again update the cache
by deleting the prev element position and added at front.
O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
	list<int>dq;   // to store cache keys double linkedlist.
	unordered_map<int, list<int>::iterator>m;  // check is it in cache and lookup.
	int capacity;
public:
	LRUCache(int n):capacity(n)
	{
	}
	void refer(int x)
	{
		// not present in cache
		if(m.find(x) == m.end())
		{
			// cache is full
			if(dq.size() == capacity)
			{
				// delete least recent used element
				int last = dq.back();
				dq.pop_back(); 

				m.erase(last);				
			}		
		}
		else
		{
			// present in cache then remove it 
			dq.erase(m[x]);
		}
		//update the reference by adding at front.
		dq.push_front(x);
		m[x] = dq.begin();
	}
	void display()
	{
		for(auto it= dq.begin(); it!= dq.end(); ++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
};

int main()
{

LRUCache ca(5);
ca.refer(1);
ca.refer(2);
ca.refer(5);
ca.refer(1);
ca.refer(5);
ca.refer(4);
ca.refer(6);
ca.refer(4);
ca.display();  // 4 6 5 1 2

return 0;
}