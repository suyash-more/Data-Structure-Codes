#ifndef ADDER_H_INCLUDED
#define ADDER_H_INCLUDED
#include<iostream>
using namespace std;


void print(int *arr,int n)
{
    cout<<" The array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

void insertion_sort(int *arr, int n)
{
    cout<<"Inside the insertion sort method"<<endl;
    int key = INT_MIN;
    int current_moving_element = -1;
    for(int i=1; i<n; i++)
    {
        key = *(arr+i);
        current_moving_element=i-1;
        while(current_moving_element>=0 &&  *(arr+current_moving_element)>key)
        {
            *(arr+current_moving_element+1) = *(arr+current_moving_element);
            current_moving_element--;
        }
        *(arr+current_moving_element+1) = key;
        cout<<"\nAfter "<<i<< " turn";
        print(arr,n);
        cout<<endl;
    }
    cout<<"\nArray sorted..!!"<<endl;
}

#endif // ADDER_H_INCLUDED
