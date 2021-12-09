#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H

class hash_table
{
    public:
        hash_table(); // constructor
        int hash_function(std::string key); 
        void add_item(std::string first_name);
        void print_table();
        void print_items(int index);
        int count_items(int index);
        void delete_item(std::string key);

    private:
        struct item // buckets to store data. Linked list
        {
            std::string first_name;
            std::string last_name;
            item* next;
        };

        static const int table_size = 10; // size of hash table
        item* table[table_size]; // array of linked list
};

#endif
