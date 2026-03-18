#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(ara[j] > ara[j + 1])
            {
                temp = ara[j];
                ara[j] = ara[j + 1];
                ara[j + 1] = temp;
                flag = 1;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    cout << "After sorting" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ara[i] << " ";
    }
    return 0;
}


