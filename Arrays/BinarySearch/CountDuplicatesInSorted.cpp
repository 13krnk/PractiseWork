/**
 * Find the Count of duplicate element in sorted array 
 * array = [ 1, 2, 3, 9, 9, 9, 9, 10, 10, 12, 13 ]
 */
//O(logn)
#include<bits/stdc++.h>
using namespace std;

int  findOccurence(int a[], int n, int k, int idx)
{
    int l =0, h = n, mid =0,res = -1;
    while(l<=h)
    {
        mid = l + (h-l)/2;
        if(a[mid] == k)
        {
            // found element at index .
            // duplicates so left and right element exist
            res = mid;
            // towards first occurence
            if(idx == 1)
            {
                h = mid -1;
            }
            else
            {
                l = mid +1;  // towards end
            }
        }
        else if(a[mid] > k)
        {
            h = mid-1;
        }
        else
        {
            l = mid +1;
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 2, 3, 9, 9, 9, 9, 10, 10, 12, 13};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 12;
    int l =0, f= 0;
    // find the first occurened
    // finf the last occurence
    // count the in btwn indexes
    f = findOccurence(a, n, k, 1); 
    if(f != -1)
    {
        l = findOccurence(a, n, k, 0); 
        cout<<l - f +1<<endl;
    }
    else
        cout<<0<<endl;
    return 0;
}
