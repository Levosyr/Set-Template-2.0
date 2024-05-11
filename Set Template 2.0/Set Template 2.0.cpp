#include <iostream>
#include "unorderedSetType.h"

using namespace std;

int main() {
    // Creating an array of integers
    int intArray[] = { 1, 2, 3, 4, 5 };
    // Creating an array of strings
    string strArray[] = { "apple", "banana", "orange", "grape", "melon" };

    // Creating unorderedSet objects for integers and strings
    unorderedSetType<int> intSet;
    unorderedSetType<string> strSet;

    // Adding integers to intSet
    for (int i = 0; i < 5; ++i)
        intSet.insertEnd(intArray[i]);

    // Adding strings to strSet
    for (int i = 0; i < 5; ++i)
        strSet.insertEnd(strArray[i]);

    cout << "Integer Set: ";
    intSet.print();

    cout << "String Set: ";
    strSet.print();

    // Testing insertAt for integer set
    intSet.insertAt(2, 6);
    cout << "Integer Set after insertAt: ";
    intSet.print();

    // Testing insertAt for string set
    strSet.insertAt(2, "pineapple");
    cout << "String Set after insertAt: ";
    strSet.print();

    // Testing replaceAt for integer set
    intSet.replaceAt(4, 10);
    cout << "Integer Set after replaceAt: ";
    intSet.print();

    // Testing replaceAt for string set
    strSet.replaceAt(4, "watermelon");
    cout << "String Set after replaceAt: ";
    strSet.print();

    // Creating two sets of integers for union and intersection
    unorderedSetType<int> intSet1, intSet2;
    intSet1.insertEnd(1);
    intSet1.insertEnd(2);
    intSet2.insertEnd(2);
    intSet2.insertEnd(3);

    // Performing union and intersection operations on sets of integers
    cout << "Union of integer sets: ";
    (intSet1 + intSet2).print();
    cout << "Intersection of integer sets: ";
    (intSet1 - intSet2).print();

    return 0;
}
