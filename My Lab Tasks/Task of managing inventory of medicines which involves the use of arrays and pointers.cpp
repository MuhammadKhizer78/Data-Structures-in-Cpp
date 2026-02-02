#include<iostream>
using namespace std;

float avgStock(int qty[], int s)
{
    int sum = 0;
    int *p = qty;
    for (int i = 0; i < s; i++)
    {
        sum = sum + *p;
        p++;
    }

    return ((float) sum / s);
}

void critProd(string p[], int qty[], int s, int avg)
{
    string *prod = p;
    int *q = qty;
    for (int i = 0; i < s; i++)
    {
        if(*(q + i) < avg)
            cout << *(prod + i) << " - " << *(q + i) << endl;

//        prod++;
//        q++;
    }
    
}

int topSelling(string p[], int s_qty[], int s) // s_qty means sold quantity.
{
    int *sq = s_qty;
    int max = *sq;
    int pos = 0;
    for (int i = 0; i < s; i++)
    {
        if(*sq > max)
        {
            max = *sq;
            pos = i;
        }

        sq++;
    }
    cout << "Best selling product is " << *(p + pos) << endl;
    /* *(p + pos) or p[pos] both are possible. */
    return max;
}

void secSelling(string p[], int s_qty[], int s, int max) 
{
//    string *prod = p;
    int *sq = s_qty;
    int s_max = *sq;
    int pos = 0;
    for (int i = 0; i < s; i++)
    {
        if(*sq > s_max && *sq < max)
        {
            s_max = *sq;
            pos = i;
        }

        sq++;
    }   
    cout << "Second Best selling product is " << p[pos] << endl;
}

void sortPopular(int s_qty[], int s)
{
    int q[s];
    for (int i = 0; i < s; i++)
    {
        *(q + i) = *(s_qty + i);
    }

    int *ptr = nullptr;
    
	for (int i = 0; i < s; i++)
    {
        ptr  = q;
        for (int j = 0; j < s - i - 1; j++)
        {
            if(*ptr < *(ptr + 1))
                swap(*ptr, *(ptr + 1));
            
            ptr++;
        }
    }

    ptr = q;
    for (int i = 0; i < s; i++)
        cout << *(ptr + i) << "\t";

    cout << endl;
}

int main()
{
    int size = 6;
    string prod[] = {"Panadol Tablets", 
                    "Flygyl Tables", 
                    "Disprin Tables", 
                    "Panadol Syrup", 
                    "Cefiget",
                    "Smecta"
                };
    int avail_qty[] = {19, 15, 58, 88, 90, 12};
    int sold_qty[] = {25, 65, 18, 65, 200, 120};

    float avg = avgStock(avail_qty, size);
    cout << "Average stock = " << avg << endl;

    critProd(prod, avail_qty, size, avg);

    int maxSelling = topSelling(prod, sold_qty, size);
    secSelling(prod, sold_qty, size, maxSelling);
    sortPopular(sold_qty, size);
}