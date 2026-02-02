#include<iostream>
using namespace std;

class Student
{
    private:
        int rollno;
        string first_name;
        float cgpa;

    public:
        void setStudent(int r, string fn, float c)
        {
            rollno = r;
            first_name = fn;
            cgpa = c;
        }

        float getCGPA()
        {
            return cgpa;
        }
};

class Heap
{
    private:
        Student *h;
        int maxSize;    // capacity
        int n;          // no of elements
    public:
        Heap(int ms)
        {
            maxSize = ms;
            h = new Student[maxSize+1];
            n = 0;
        }
        void insert(Student x);
        void print();
        Student deleteMax();
        void heapify(int i);
        void buildHeap();
};

void Heap::insert(Student x)
{
    if(n == maxSize)
    {
        cout<<"Heap is full"<<endl;
        return;
    }

    n++;
    int i;
    for (i = n; i > 1; i = i/2)
    {
        if (x.getCGPA() <= h[i/2].getCGPA())
            break;

        h[i] = h[i/2]; 
        // h[i/2] = x;    
    }
    h[i] = x;
}

void Heap::print()
{
    for (int i = 1; i <= n; i++)
        cout<<h[i].getCGPA()<<"\t";
    cout<<endl;
}

Student Heap::deleteMax()
{
    Student root = h[1]; 
    h[1] = h[n]; //assign last element to first
    n--;
    heapify(1);
    return root;
}

void Heap::heapify(int i) 
{ 
    int smallest = i; // Initialize smallest as root 
    int l = 2 * i; // left = 2*i 
    int r = 2 * i + 1; // right = 2*i + 1
  
    // If left child is larger than root 
    if (l <= n && h[l].getCGPA() > h[smallest].getCGPA()) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r <= n && h[r].getCGPA() > h[smallest].getCGPA()) 
        smallest = r; 
  
    // If smallest is not parent 
    if (smallest != i) 
    { 
        swap(h[i], h[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(smallest); 
    } 
} 
  
// Function to build a Min-Heap from the given array 
void Heap::buildHeap()
{ 
    // Index of last non-leaf node 
    int startIdx = (n / 2); 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i > 0; i--)
        heapify(i); 
}

int main()
{
    Student s1, s2, s3, s4;
    s1.setStudent(1, "Ali", 2.87);
    s2.setStudent(2, "Waqar", 2.67);
    s3.setStudent(10, "Kashif", 4.00);
    s4.setStudent(5, "Aisha", 3.45);

    Heap h(6);
    h.insert(s1);
    h.insert(s2);
    h.insert(s3);
    h.insert(s4);
    h.print();
    h.deleteMax();
    h.print();
}