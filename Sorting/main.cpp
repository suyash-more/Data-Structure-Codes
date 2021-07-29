#include <iostream>
#include "adder.h"

using namespace std;

int main()
{
    int arr[]={4,1,2,6,8,9};
    int n = sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);
    print(arr,n);
    return 0;
}
