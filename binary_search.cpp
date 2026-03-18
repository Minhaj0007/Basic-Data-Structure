#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    int s_value, left = 0, right = n - 1;
    cin >> s_value;
    int flag = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(ara[mid] == s_value)
        {
            cout << "The value is found at index : " << mid;
            flag = 1;
            break;
        }
        else if(ara[mid] > s_value)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(flag == 0)
    {
        cout << "The value is not found";
    }
    return 0;
    
}


