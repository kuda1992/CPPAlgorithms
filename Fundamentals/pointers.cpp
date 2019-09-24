#include "iostream"

void geeks() {

    int var = 20;

    // declare a pointer variable
    int *ptr;

    ptr = &var;

    // assign the address of a variable to a pointer
    std::cout << "Value at ptr = " << ptr << "\n";
    std::cout << "Value at var = " << var << "\n";
    std::cout << "Value at *ptr = " << *ptr << "\n";
}
/*

int main () {

    geeks();
}*/
