#include <iostream>
using namespace std;

class HashTable
{
private:
    int *arr;
    int capacity;
    int n;

public:
    HashTable(int s)
    {
        capacity = s;
        arr = new int[capacity];
        n = 0;

        for (int i = 0; i < capacity; i++) // for empty
            arr[i] = -1;
    }

    int hash(int val) // Gives us location (index) for the value
    {
        return (val % capacity);
    }

    void rehash()
    {
        n = 0;
        int newSize = capacity * 2;
        int *oldArr = arr;
        arr = new int[newSize];

        for (int i = 0; i < newSize; i++) // for empty
            arr[i] = -1;

        int c = capacity;
        capacity = newSize;

        for (int i = 0; i < c; i++)
        {
            if (oldArr[i] != -1)
                insert(oldArr[i]);
        }
    }

    void insert(int val)
    {
        if (n == capacity)
        {
            cout << "The Table is full!";
            return;
        }
        n++;
        float load_factor = (float) n / capacity;
        // cout << "Load Factor: " << load_factor << endl;

        if (load_factor > 0.7) // Rehash
            rehash();

        int index = hash(val);

        while (arr[index] != -1) // Collision Occured
        {
            if (index == (capacity - 1))
                index = 0;
            else
                index++;
        }

        arr[index] = val;
    }

    bool search(int val)
    {
        if (n == 0)
        {
            cout << "The Table is empty!";
            return false;
        }

        int index = hash(val);

        while (arr[index] != -1)
        {
            if (arr[index] == val)
                return true;

            if (index == (capacity - 1))
                index = 0;
            else
                index++;
        }
        return false;
    }

    void printTable()
    {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }
};

int main()
{
    HashTable h(7);
    h.insert(15);
    h.insert(1);
    h.insert(10);
    h.insert(21);
    h.printTable();
    h.insert(14);
    h.printTable();
    cout << h.search(4) << endl;
}