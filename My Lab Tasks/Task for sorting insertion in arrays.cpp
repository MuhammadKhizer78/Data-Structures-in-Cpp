#include<iostream>

using namespace std;

void printArr(int arr[], int l)
{
    for (int i = 0; i < l; i++)
        cout << arr[i] << "\t";

    cout << endl;
}

bool isAscending(int arr[], int l)
{
    int *start = arr;
    int *end = arr + l - 1;

    if(*start <= *end)
        return true;
    else
        return false;
}

void sortedInsert(int arr[], int &l, int c, int val)
{
    if(l == c)
    {
        cout << "List is full, cannot insert!" << endl;
        return;
    }
    int pos = 1;
    int *curr = arr;

    if(isAscending(arr, l))
    {
        for (int i = 1; i <= l; i++)
        {
            if(val <= *curr)
                break;
            
            curr++;
            pos++;
        }

        curr = arr + l - 1; // end
        for (int i = l; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            curr--;
        }
        *(curr + 1) = val;
        l++;
    }
    else
    {
        for (int i = 1; i <= l; i++)
        {
            if(val >= *curr)
                break;
            
            curr++;
            pos++;
        }

        curr = arr + l - 1; // end
        for (int i = l; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            curr--;
        }
        *(curr + 1) = val;
        l++;
    }
}

int main()
{
    const int capacity = 10;
    int arr[capacity] = {1, 4, 6, 11, 14};
    int length = 5;
    printArr(arr, length);
    sortedInsert(arr, length,capacity, 8);
    printArr(arr, length);
    sortedInsert(arr, length,capacity, 2);
    printArr(arr, length);
    sortedInsert(arr, length,capacity, -1);
    printArr(arr, length);
    sortedInsert(arr, length,capacity, 18);
    printArr(arr, length);
}