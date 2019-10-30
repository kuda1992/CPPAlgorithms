#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>


template<typename Value>
class HashTable {
private:
    size_t m = 0;
    size_t count = 0;
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;

    std::vector<std::list<Value>> data;


    size_t hash(Value value) {
        unsigned long long hash = 0;
        for (int i = static_cast<int> (value.size()) - 1; i >= 0; --i) {
            hash = (hash * multiplier + value[i]) % prime;
        }
        return hash % m;
    }

public:

    HashTable() {
        data.resize(10);
    }

    HashTable(size_t size) : m(size) {
        data.resize(size);
    }

    void resize(size_t size) {
        data.resize(size);
        m = size;
    }

    void put(Value value) {
        size_t hash_index = hash(value);
        if (!has_key(value)) {

            std::list<Value> *item_pos = &data.at(hash_index);

            item_pos->push_back(value);
            count++;
        }

        std::list<Value> *item_pos = &data.at(hash_index);

        for (Value &pair: *(item_pos)) {
            if (pair == value) {
                pair = value;
            }
        }
    }

    void check_results_at_specific_index(size_t index) {

        std::list<Value> *item_pos = &data.at(index);
        item_pos->reverse();

        for (Value &item: *(item_pos)) {
            if (hash(item) == index) {
                std::cout << item << " ";
            }
        }
        std::cout << "\n";
    }


    Value get(Value value) {

        Value _value = "not found";

        if (has_key(value)) {
            size_t hash_index = hash(value);

            std::list<Value> *item_pos = &data[hash_index];

            for (const Value &pair: *(item_pos)) {
                if (pair == value) {
                    _value = pair;
                    return _value;
                }
            }
        }

        return _value;
    }

    bool has_key(Value value) {

        bool key_found = false;
        size_t hash_index = hash(value);
        std::list<Value> *item_pos = &data[hash_index];

        for (const Value &_value: *(item_pos)) {
            if (_value == value) {
                key_found = true;
                return key_found;
            }
        }

        return key_found;
    }

    void remove(Value value) {

        if (has_key(value)) {
            size_t hash_index = hash(value);

            std::list<Value> *item_pos = &data[hash_index];

            item_pos->remove_if([&value](const Value &item) { return item == value; });

            count--;

        }
    }


    size_t size() {
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
    size_t bucket_count;

    HashTable<std::string> words;

public:

    explicit QueryProcessor(size_t bucket_count) : bucket_count(bucket_count) {
        words.resize(bucket_count);
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

    void write_search_result(std::string &result) const {
        std::cout << (result != "not found" ? "yes\n" : "no\n");
    }

    void process_query(const Query &query) {

        if (query.type == "check") {
            words.check_results_at_specific_index(query.index);
        } else {

            if (query.type == "find") {
                std::string result = words.get(query.s);
                write_search_result(result);
            } else if (query.type == "add") {
                if (!words.has_key(query.s)) words.put(query.s);
            } else if (query.type == "del") {

                if (words.has_key(query.s)) words.remove(query.s);

            }

        }
    }

    void process_queries() {
        size_t n;
        std::cin >> n;

        for (size_t i = 0; i < n; i++)
            process_query(read_query());
    }
};

/*
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t bucket_count;
    std::cin >> bucket_count;
    QueryProcessor processor(bucket_count);
    processor.process_queries();
    return 0;
}*/

