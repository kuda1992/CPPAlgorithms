
#include "iostream"
#include "stack"
#include "string"


struct Bracket {

    char type;
    int position;

    Bracket(char type, int position) : type(type), position(position) {}

    Bracket(Bracket &bracket) {
        type = bracket.type;
        position = bracket.position;
    }

    Bracket(Bracket &&bracket) {
        type = bracket.type;
        position = bracket.position;
    }

    bool match_character(char c) {

        if (type == '[' && c == ']') {
            return true;
        }

        if (type == '{' && c == '}') {
            return true;
        }

        return type == '(' && c == ')';

    }
};

/*
int main() {

    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {

        char next = text[position];

        if (next != '(' && next != ')' && next != '{' && next != '}' && next != '[' && next != ']') {
            continue;
        }

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket{next, position});
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here

            if (opening_brackets_stack.empty()) {
                // either does not have an opening bracket before it
                std::cout << position + 1 << std::endl;
                return position + 1;
            } else {
                Bracket top = opening_brackets_stack.top();
                opening_brackets_stack.pop();


                if (!top.match_character(next)) {
                    std::cout << position + 1 << std::endl;
                    return position + 1;
                }
            }
        }
    }

    if (opening_brackets_stack.empty()) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << opening_brackets_stack.top().position + 1 << std::endl;
    }
    return 0;
}*/
