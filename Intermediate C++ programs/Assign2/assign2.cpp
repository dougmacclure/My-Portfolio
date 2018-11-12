#include <iomanip>
#include <iostream>
#include "Store.h"


using namespace std;

int main()
{

Store store1("storedata");

store1.print();

/**
Create a Store object using the alternate constructor you wrote. Pass the filename string "storedata" as an argument to the constructor.
Call the print() method for the Store object.
Call the processOrders() method for the Store object. Pass the filename string "orders.txt" as an argument to the method.
Call the print() method for the Store object.
*/

store1.processOrders("orders.txt");
store1.print();

return 0;
}

