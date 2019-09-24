#include "iostream"
#include "vector"
#include "algorithm"
#include "type_traits"


template<typename Key, typename Value>
class Map {
    int size_;
    int count;
    std::vector<std::vector<std::pair<Key, Value>>> data;


    int hash(Key key) {

        // check if key is a string
        if (std::is_same<Key, std::string>::value) {
            int sum;

            for (char c: key) {
                sum += (int) c;
            }

            return sum % size_;
        }

    }

public:

    Map(int size) : size_(size) {
        data.resize(10);
        for (std::vector<std::pair<Key, Value>> chain: data) {
            chain.resize(2);
        }
    }

    void put(Key key, Value value) {
        int hash_index = hash(key);
        std::vector<std::pair<Key, Value>> *item_pos = &data.at(hash_index);

        std::pair<Key, Value> pair = std::make_pair(key, value);

        item_pos->push_back(pair);
        count++;

    }

    Value get(Key key) {
        int hash_index = hash(key);
        if (has_key(key)) {
            std::vector<std::pair<Key, Value>> *item_pos = &data[hash_index];
            for (std::pair<Key, Value> &pair: *(item_pos)) {
                if (pair.first == key) {
                    return pair.second;
                }
            }
        }
        return nullptr;
    }

    void remove(Key key) {

    }

    bool has_key(Key key) {
        bool key_found = false;
        int hash_index = hash(key);
        std::vector<std::pair<Key, Value>> *item_pos = &data[hash_index];
        for (std::pair<Key, Value> pair: *(item_pos)) {
            if (pair.first == key) {
                key_found = true;
                return key_found;
            }
        }
        return key_found;
    }

    int size() {
        return count;
    }
};

/*
int main() {


    Map<std::string, std::string> map(10);

    map.put("kuda", "07896582805");
    map.put("thomas", "07896582205");
    map.put("maka", "07896582305");

    std::cout << "the size of the map is " << map.size() << std::endl;

    std::cout << "the value of thomas is " << map.get("thomas") << std::endl;
}*/
