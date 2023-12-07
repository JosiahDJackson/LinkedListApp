//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999 

#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>



using namespace std;

int main()
{

    /************** MY LIST TESTER ****************/

    unorderedLinkedList<int> ulist;
    orderedLinkedList<int> olist;

    try {

        vector<int> intVector;
        for (const auto x : { 20,80,30,40,55,11,12,13,1,2,0,44,66,55,77,22,88,12,23,97 })
            intVector.push_back(x);

        vector<int> intVector2;
        for (const auto x : { 80,55,0,77,22,88,23,97 })
            intVector2.push_back(x);
   

         ulist.insertLast(intVector);
         olist.insertFirst(intVector);

        cout << "ulist: "; 
        ulist.print();
        cout << endl;
        cout << "Length of ulist: " << ulist.length() << endl;

        cout << "\nolist: ";
        olist.print();
        cout << endl;
        cout << "Length of olist: " << olist.length() << endl;

        ulist.deleteNode(intVector);
        olist.deleteNode(intVector);

        cout << "\nAfter deleting from ulist: ";
        ulist.print();
        cout << endl;
        cout << "Length of ulist: " << ulist.length() << endl;

        cout << "\nAfter deleting from olist: ";
        olist.print();
        cout << endl;
        cout << "Length of olist: " << olist.length() << endl;

        orderedLinkedList<int> olist2;

        olist2.deleteNode(3);   //test exception


    }
    catch (listException e) {
        cout << "\nList exception caight in main: " << e.what() << endl;
    }
    catch (exception e) {
        cout << "\nSTD exception caight in main: " << e.what() << endl;
    }

    /*           Demonstrate STL List container */

    std::list<int> list1 = { 5, 2, 9, 1, 7, 12, 3 };
    std::list<int> list2 = { 4, 8, 3, 6, 10, 15, 2 };
    std::list<int> list3 = { 11, 14, 9, 5, 6, 1, 13 };

    list1.sort();
    list2.sort();
    list3.sort();

    list1.merge(list2);
    list1.merge(list3);

    std::cout << "\nMerged and Sorted List: ";
    for (const auto& value : list1) {
        std::cout << value << " ";
    }

    std::cout << std::endl;


    return 0;
}



