/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[5],i,*p;
    cout<<"Enter the elements";
    for(i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    p=arr;
     cout<<"You entered \n";
     
    for(i=0;i<5;i++)
    {
        cout<<*p<<endl;
        p++;
    }
    
    

    return 0;
}
