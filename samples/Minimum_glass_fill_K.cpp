
/*

Minimum number of glasses that you need to fill exactly with K ltrs of water
N - no of glasses with each of unique capacity
K - water ltrs

N = 5, K = 8
o/p:2
glasses 1 2 3 4 5 
3 5 are two glasses to fill the exact K ltr.

N = 1, K =2
o/p: -1
No glas can fill 2ltr
*/

#include <bits/stdc++.h>
using namespace std;
int minBottles(int N, int K)
{
   int count = 0;
   while(K>0 && N>0)
   {
   		if(K>=N)
   		{
   			count++;
   			K = K -N;
   		}
   		N--;
   }
   
   if(K ==0)
		return count;
	else
		return -1;
}

int main() {
   
   cout << "Min bottles required = " <<minBottles( 5, 8) << endl;
   return 0;
}