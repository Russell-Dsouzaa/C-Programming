#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 256    // we can undefine macros as follows: #undef MAX_NAME (keep in mind, while defining or undefining macros, we do not end LOC(s) with ';'(semi-colon))
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person* hash_table[TABLE_SIZE];    // creates a hash table. It creates an array of 'person' datatype of size 'TABLE_SIZE'. This array is static i.e. collisions would not overwrite existing values

unsigned int hash (char* name)
{
    int length = strnlen(name,MAX_NAME);    // difference between strlen and strnlen is that, strlen counts number of characters in a string until it encounters a NUL character(\0) while strnlen counts number of characters unptill a specified value and then stops counting further
    unsigned int hash_value = 0;

    for (int i = 0;i < length;i++)
    {
        hash_value = hash_value + name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

bool hash_table_insert(person* p)
{
    if (p == NULL)
    {
        return false;
    }

    int index = hash(p->name);

    if (hash_table[index] != NULL)
    {
        return false;    // collsions, for now we don't handle collisions, we simply return false incase collisions occur and the existing values aren't overwritten
    }

    hash_table[index] = p;
    return true;
}

void init_hash_table()
{
    for (int i = 0;i < TABLE_SIZE;i++)
    {
        hash_table[i] = NULL;
    }
}

void print_hash_table()
{
    for (int i = 0;i < TABLE_SIZE;i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("%d ---\n",i);
        }
        else
        {
            printf("%d --> %s\n",i,hash_table[i]->name);
        }
    }
}

int main()
{
    init_hash_table();
    print_hash_table();
    printf("\n\nend\n\nstart\n");

    person Russell = {.name = "Russell", .age = 22};

    hash_table_insert(&Russell);

    print_hash_table();

    return 0;
}