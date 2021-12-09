#include <iostream>
#include <string>
#include <vector>
#include "hash.h"

hash_table::hash_table()
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = new item;
        table[i]->first_name = "empty";
        table[i]->last_name = "empty";
        table[i]->next = NULL;
    }
}

int hash_table::hash_function(std::string key)
{
    // Compute the key's hash code and then map it to an index in the array

    int hash_code = 0;
    int index;
    for(int i = 0; i < key.length(); i++)
    {
        hash_code += (int)key[i]; // ASCII of letter
    }
    
    index = hash_code % table_size;

    return index;
}

void hash_table::add_item(std::string first_name)
{
    // Adds a new item to the array. Takes care of collisions

    int index = hash_function(first_name);
    
    if(table[index]->first_name == "empty")
    {
        table[index]->first_name = first_name;
        table[index]->next = NULL;
    } 
    else
    {
        item* ptr = table[index];
        item* new_item = new item;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        new_item->first_name = first_name;
        new_item->next = NULL;

        ptr->next = new_item;
    }
}

void hash_table::print_table()
{
    // Prints the data in the array along with number of items it contains.

    for(int i = 0; i < table_size; i++)
    {
        std::cout << "----------------------" << std::endl;
        std::cout << "Index: " << i << std::endl;
        std::cout << "First Name: " << table[i]->first_name << std::endl;
        std::cout << "Last Name: " << table[i]->last_name << std::endl;
        std::cout << "Items: " << count_items(i) << std::endl;
        std::cout << "----------------------" << std::endl;
    }
}

void hash_table::print_items(int index)
{
    // Prints all the items in the given index
    
    if(table[index]->first_name == "empty")
        std::cout << "Index is empty" << std::endl;
    else
    {
        item* ptr = table[index];
        std::cout << "----------------------" << std::endl;
        std::cout << "First Name: " << ptr->first_name << std::endl;
        std::cout << "Last Name: " << ptr->last_name << std::endl;
        std::cout << "" << std::endl;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            std::cout << "First Name: " << ptr->first_name << std::endl;
            std::cout << "Last Name: " << ptr->last_name << std::endl;
            std::cout << "" << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    }

}

int hash_table::count_items(int index)
{
    // Returns the number of items found at an specific index in the array
    int count = 0;
    if(table[index]->first_name == "empty")
        return count;
    else
    {
        count++;
        item* ptr = table[index];
        while(ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}

void hash_table::delete_item(std::string key)
{
    // Given a key, it deletes the item associated with it from the table
    
    int index = hash_function(key);
    if(table[index]->first_name == key) // Key is found first on the list
    {
        if(table[index]->next == NULL)
        {
            table[index]->first_name = "empty";
            table[index]->last_name = "empty";
        }
        else
        {
            item* ptr = table[index]->next; 
            table[index] = NULL;
            delete table[index];
            table[index] = ptr;
        }
    } 
    else // Key is not first on the list
    {   
        item* ptr = table[index];
        item* previous_ptr = table[index];
        while(ptr->next != NULL)
        {
            ptr = ptr->next; // Move to next item

            if(ptr->first_name == key)
            {
                // delete this item and assing next of previous pointer to the current next
                item* next_ptr = ptr->next; 
                ptr = NULL;
                delete ptr;
                previous_ptr->next = next_ptr;
                return;
            } 

            previous_ptr = ptr;
        }
        
        std::cout << "\"" << key << "\"" << " was not found" << std::endl;
    }
}





int main()
{
    std::vector<std::string> first_names = {"Andres", "Elon"};
    std::vector<std::string> last_names = {"Vourakis", "Musk"};
    
    hash_table test;

    for(std::vector<std::string>::size_type i = 0; i != first_names.size(); i++)
    {
        test.add_item(first_names[i]);
    }

    test.print_table();
    
    int index = test.hash_function("Siraj");
    std::cout << "Before delete" << std::endl;
   // test.print_items(index);
    test.delete_item("Siraj");
    std::cout << "After delete" << std::endl;
    //test.print_table();
    //test.print_items(index);

    return 0;
}
