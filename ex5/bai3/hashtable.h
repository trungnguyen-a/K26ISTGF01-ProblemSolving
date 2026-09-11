#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Entry
{
    int value;
    struct Entry* next;
} Entry;

typedef struct Hashtable
{
    Entry** buckets;
    int capacity;
} Hashtable;

Hashtable* ht_create(int size);
int ht_put(Hashtable* ht, int value);
int ht_contain(Hashtable*ht, int value);
int ht_get(Hashtable*ht, int value);
void print_table(Hashtable* ht);
void ht_destroy(Hashtable* ht);

#endif