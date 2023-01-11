#include <iostream>
#include <fstream>
#include <sstream>
#include "Array.h"
#include "E3Point.h"

using namespace std;

int main()
{
    ifstream f_int_1("int_1.txt");
    ifstream f_int_2("int_2.txt");

    Array<int>* intArr1 = new Array<int>(5);
    Array<int>* intArr2 = new Array<int>(8);

    if(f_int_1.is_open()) {
        while (f_int_1.good()) {
            int num;
            f_int_1 >> num;
            intArr1->addElem(num);
        }
    }
    else {
        cout << "[INFO] File int_1.txt is not opened!" << endl;
    }
    f_int_1.close();

    if(f_int_2.is_open()) {
        while (f_int_2.good()) {
            int num;
            f_int_2 >> num; 
            intArr2->addElem(num);
        }
    }
    else
    {
        cout << "[INFO] File int_2.txt is not opened!" << endl;
    }
    f_int_2.close();

    Array<int>* intArr3 = new Array<int>();
    *intArr3 = *intArr2; //Koriscenje operatora =
    Array<int>* intArr4 = *intArr1 + *intArr2; //Koriscenje operatora +

    cout << "Size intArr3: " << intArr3->getSize() << endl; 
    intArr3->print(); 

    cout << "Size intArr4: " << intArr4->getSize() << endl;
    intArr4->print(); 

    delete intArr1;
    delete intArr2;
    delete intArr3;
    delete intArr4;


    ////////-----E3POINT-----////////


    Array<E3Point>* e3Arr1 = new Array<E3Point>(3);
    Array<E3Point>* e3Arr2 = new Array<E3Point>(5);

    //int brE3Pointa;
    //cout << "Unesite broj E3Pointa za .. niz: " << endl;
    //cin >> brE3Pointa;

    E3Point** e3ArrPP = new E3Point*[8];
    for (int i = 0; i < 8; i++)
    {
        e3ArrPP[i] = new E3Point();
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> *e3ArrPP[i];
        e3Arr1->addElem(*e3ArrPP[i]);
    }
    for (int i = 3; i < 8; i++)
    {
        cin >> *e3ArrPP[i];
        e3Arr2->addElem(*e3ArrPP[i]);
    }

    Array<E3Point>* e3Arr3 = new Array<E3Point>();
    *e3Arr3 = *e3Arr1; //Koriscenje operatora =
    Array<E3Point>* e3Arr4 = *e3Arr1 + *e3Arr2; //Koriscenje operatora +

    cout << "Size e3Arr3 : " << e3Arr3->getSize() << endl;
    e3Arr3->print(); 

    cout << "Size e3Arr4 : " << e3Arr4->getSize() << endl; 
    e3Arr4->print(); 

    delete e3Arr1;
    delete e3Arr2;
    delete e3Arr3;
    delete e3Arr4;

    for (int i = 0; i < 8; i++)
    {
        delete e3ArrPP[i];
    }
    delete[] e3ArrPP;

    return 0;
}
