#include <iostream>
using namespace std;

void increment(int *a)
{
    *a = *a + 10;
}

void part_1()
{
    int a = 10;
    int *p = &a; // Pointer Initialization
    cout << "Address of Variable: " << p << endl;
    cout << "Value of Variable: " << *p << endl; // Dereferencing
    // Updating value through pointers
    *p = 20;
    cout << "Value of Variable: " << a << endl;
    increment(&a);
    cout << "After increment: " << a << endl;
}

void part_2()
{
    cout << "Pointer Arithmetic" << endl;
    int a = 5;
    int *p = &a;
    // If p = 2001, then p + 1 = 2005 and p + 2 = 2009
    cout << p << " " << p + 1 << endl; // Increments by size of data type
    cout << *p + 1 << endl;
    cout << *(p + 1) << endl;
}

void part_3()
{
    cout << "Pointer Typecasting" << endl;
    int a = 1025;
    int *p = &a;
    char *p2 = (char *)p;
    void *ptr = &a;
    cout << *(int *)ptr << endl;
}

void part_4()
{
    cout << "Pointer to Pointer" << endl;
    int a = 1025;
    int *p = &a;
    int **q = &p;
    cout << **q << endl;
}

void part_5()
{
    cout << "Characters & Pointer" << endl;
    char c[] = "Abhishek";
    char *ptr = &c[0];
    cout << ptr << endl;
    cout << ptr[0] << endl;
}

void part_6()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << arr << endl;        // Base Address of Array
    cout << &arr[3] << endl;    // Address of that index
    cout << *(arr + 2) << endl; // get value at index by incrementing pointer

    int *ptr = arr;
    int *ptr2 = arr + 4;
    cout << *ptr << " " << *ptr2 << endl;
    cout << ptr2 - ptr << endl;
}

void part_7()
{
    int A[] = {1, 2, 3, 4, 5};
    cout << A << endl;
    char B[] = "Abhi";
    char *ptr = B;
    cout << &(++ptr) << endl;
}

void part_8()
{
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << A + 1 << " " << A + 2 << endl;
    int(*ptr)[3] = A + 1;
    cout << *(ptr[0]) << endl;
}

int main()
{
    // part_1();
    // part_2();
    // part_3();
    // part_4();
    // part_5();
    // part_6();
    // part_7();
    // part_8();

    return 0;
}
