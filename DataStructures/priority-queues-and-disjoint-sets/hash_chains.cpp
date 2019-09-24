#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>


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



struct Query {
    std::string type;
    std::string s;
    size_t index;
};


class QueryProcessor {

private:
    int bucket_count;

    // store all strings in one vector
    std::vector<std::string> elements;

    size_t hash_function(const std::string &s) {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;

        unsigned long long hash = 0;

        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i) {
            hash = (hash * multiplier + s[i]) % prime;
        }
        return hash % bucket_count;
    }

public:

    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) {

    }

    Query read_query() const {

        Query query;
        std::cin >> query.type;

        if (query.type != "check") {
            std::cin >> query.s;
        } else {
            std::cin >> query.index;
        }
        return query;
    }

    void write_search_result(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void process_query(const Query &query) {

        if (query.type == "check") {

            // use the reverse order, because we append strings to the end
            for (int i = static_cast<int>(elements.size()) - 1; i >= 0; --i)
                if (hash_function(elements[i]) == query.index)
                    std::cout << elements[i] << " ";
            std::cout << "\n";
        } else {

            std::vector<std::string>::iterator it = std::find(elements.begin(), elements.end(), query.s);

            if (query.type == "find") {
                write_search_result(it != elements.end());
            } else if (query.type == "add") {

                if (it == elements.end()) {
                    elements.push_back(query.s);
                }
            } else if (query.type == "del") {
                if (it != elements.end()) {
                    elements.erase(it);
                }

            }

        }
    }

    void process_queries() {
        int n;
        std::cin >> n;

        for (int i = 0; i < n; n++)
            process_query(read_query());
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    std::cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.process_queries();
    return 0;
}

