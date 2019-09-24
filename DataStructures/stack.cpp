#include "string"
#include "iostream"
#include "vector"


template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(T &value) {

        elements.push_back(value);
    }

    T pop() {
        T removed_element = elements.back();
        elements.pop_back();
        return removed_element;
    }

    bool isEmpty() {
        return elements.empty();
    }

};

bool is_balanced(const std::string &string) {

    Stack<char> stack;

    for (const auto &character: string) {
        if (character == '[' || character == '(') {
            stack.push(const_cast<char &>(character));
        } else {
            if (stack.isEmpty())
                return false;

            char top = stack.pop();

            if ((top == '[' && character != ']') || (top == '(' && character != ')')) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}


//int main() {
//    std::string result = is_balanced("[]()") ? "yes" : "no";
//    std::cout << "is the string is balanced " << result << std::endl;
//}


