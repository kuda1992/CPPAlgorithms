#include <iostream>

#include "Stack.cpp"

int main () {

    Stack<int> stackOfNumbers;


    stackOfNumbers.push(1);
    stackOfNumbers.push(2);
    stackOfNumbers.push(3);
    stackOfNumbers.push(4);
    stackOfNumbers.push(5);
    stackOfNumbers.push(6);


    std::cout << "we are now popping the last element of the stack " << stackOfNumbers.pop() << "\n";



    return 0;
}
