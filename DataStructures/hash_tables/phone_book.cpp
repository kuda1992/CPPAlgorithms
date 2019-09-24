#include "iostream"
#include "vector"
#include "list"
#include "string"
#include <cstdlib>
#include <cmath>


struct Query {
    std::string type;
    std::string name;
    int number;
};

template<typename Key, typename Value>
class HashTable {
private:
    int m = 101;
    int a = -1;
    int b = -1;
    int count{};


    std::vector<std::list<std::pair<Key, Value>>> data;

    int next_prime(int n) {

        if (n % 2 == 0)
            n++;

        while (!is_prime(n))
            n += 2;

        return 2;
    }

    int random(int min, int max) {
        static bool first = true;
        if (first) {
            srand(time(NULL)); //seeding for the first time only!
            first = false;
        }
        return min + std::rand() % ((max + 1) - min);
    }

    bool is_prime(int n) {
        if (n % 2 == 0)
            return false;

        // ignore all the even numbers and check till sqrt(n)
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int hash(Key number) {

        return number % m;
    }

public:

    HashTable() {
        data.resize(m);
    }

    void put(Key key, Value value) {
        int hash_index = hash(key);
        std::pair<Key, Value> pair = std::make_pair(key, value);
        if (!has_key(key)) {

            std::list<std::pair<Key, Value>> *item_pos = &data.at(hash_index);

            item_pos->push_back(pair);
            count++;
        }

        std::list<std::pair<Key, Value>> *item_pos = &data.at(hash_index);

        for (std::pair<Key, Value> &pair: *(item_pos)) {
            if (pair.first == key) {
                pair.second = value;
            }
        }
    }


    Value get(Key key) {

        Value value = "not found";

        if (has_key(key)) {
            int hash_index = hash(key);

            std::list<std::pair<Key, Value>> *item_pos = &data[hash_index];

            for (const std::pair<Key, Value> &pair: *(item_pos)) {
                if (pair.first == key) {
                    value = pair.second;
                    return value;
                }
            }
        }

        return value;
    }

    bool has_key(Key key) {

        bool key_found = false;
        int hash_index = hash(key);

        std::list<std::pair<Key, Value>> *item_pos = &data[hash_index];


        for (const std::pair<Key, Value> &pair: *(item_pos)) {
            if (pair.first == key) {
                key_found = true;
                return key_found;
            }
        }

        return key_found;
    }

    void remove(Key key) {

        if (has_key(key)) {
            int hash_index = hash(key);

            std::list<std::pair<Key, Value>> *item_pos = &data[hash_index];

            item_pos->remove_if([&key](const std::pair<Key, Value> &item) { return item.first == key; });

            count--;

        }
    }


    int size() {
        return count;
    }

};

/**
 * Phone book manager.
 * <p>
 * Query contact names by phone numbers.</br>
 * add number name: adds a person with name name
 *                  and phone number number to the
 *                  phone book; overwrite name if
 *                  exists.</br>
 * del number:  erase a person with number from
 *              the phone book. ignore if there
 *              is no such person.</br>
 * find number: looks for a person with phone
 *              number number; reply with “not
 *              found” if there is no such person.</br>
 * Constraints: 1 ≤ N ≤ 10^5;
 *              all phone numbers have no more
 *              than 7 digits;
 *              all names have length at most 15
 */

class PhoneBook {
private:

    HashTable<int, std::string> contacts;
    std::vector<std::string> results;
    std::vector<Query> queries;
public:
    void read_queries() {
        int n;
        std::cin >> n;

        queries.resize(n);
        for (int i = 0; i < n; i++) {

            std::cin >> queries[i].type;

            if (queries[i].type == "add") {
                std::cin >> queries[i].number >> queries[i].name;
            } else {
                std::cin >> queries[i].number;
            }
        }
    }

    void write_responses() {

        for (const std::string &result: results)
            std::cout << result << std::endl;
    }

    void insert(Query query) {
        contacts.put(query.number, query.name);

    }

    void remove(Query query) {

        contacts.remove(query.number);
    }

    std::string find(Query query) {

        const std::string result = contacts.get(query.number);

        return result;
    }

    void process_queries() {
        for (const Query &query: queries) {
            if (query.type == "add") {
                insert(query);
            } else if (query.type == "del") {
                remove(query);
            } else {

                std::string response = find(query);
                results.push_back(response);
            }
        }
    }
};

/*
int main() {


    PhoneBook phoneBook;

    phoneBook.read_queries();
    phoneBook.process_queries();
    phoneBook.write_responses();
    return 0;
}*/
