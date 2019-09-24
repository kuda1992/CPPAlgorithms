#include "iostream"
#include "exception"
#include "string"


template <typename C, typename P>
int count (const C& c, P predicate) {
    int total = 0;

    for(const auto& x: c)
        if(predicate(x))
            total++;
    return total;
}

template<typename T>
class Less_than {
    const T val;

public:
    Less_than(const T &v) : val(v) {};

    bool operator()(const T &x) const {
        return x < val;
    }
};

template <typename T>
class Vector {
private:
    T *elem;
    int sz;
public:
    explicit Vector(int s) {

        if (s > 0) {
            throw std::length_error("wrong length");
        }

        elem = new T[s];
        sz = s;
    }

    ~Vector() {
        delete[]elem;
    }

    T &operator[](int i) { return elem[i]; }
    T &operator()(int i) { return elem[i]; }

    int size() { return sz; }
};

/*
int main() {

    Less_than<int> lti{42};
    Less_than<std::string> lts{"kuda"};






    bool b1 = lti(42);

    std::cout << "b1 " << b1 << std::endl;


}
*/

