/**
 *  Given string is valid ip4 address or not
 *   s = "192.1.20.254" 
 *   o/p : 
 *   true 
 *   s = "192.168..0"
 *   o/p:
 *   false
 * ---
 * ip4 address conditions
 * full octat 192.168.100.255 = 15 chars
 * ip4 only includes digits
 * dots should not come one after another
 * start of string always digit
 * each octat should less than 255
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 15
bool isValidIp4(string s)
{
    bool res = true;
    int n = s.size();
    if(n > MAX_LEN || s[n-1] == '.')
    {
        return false;
    }
    int dot = 0;
    int num = 0;
    for(int i =0; i< n ; i++)
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + s[i] - '0';
            if(num > 255)
            {
                res = false;
                break;
            }
        }
        else if(i>0 && s[i] == '.' && s[i-1] != '.' && dot <3)
        {
            dot++;
            num = 0;
        }
        else
        {
            res = false;
            break;
        }        
    }
    
    return res;
}

int main()
{
    string s = "192.168.1.255";  
    string s1 = "19b.168.1.10";  
    string s2 = "10.1..0";  
    string s3 = ".10.15.119";  
    string s4 = "192.0.0.256";  
    string s5 = "192.1.1.1";  
    string s6 = "192.1.1.1000";  
    string s7 = "10.1.1.";  
    cout<<isValidIp4(s)<<endl;   // 1
    cout<<isValidIp4(s1)<<endl;  // 0 
    cout<<isValidIp4(s2)<<endl;  // 0
    cout<<isValidIp4(s3)<<endl;  // 0
    cout<<isValidIp4(s4)<<endl;  // 0
    cout<<isValidIp4(s5)<<endl;  // 1
    cout<<isValidIp4(s6)<<endl;  // 0
    cout<<isValidIp4(s7)<<endl;  // 0

    return 0;
}