#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Entry
{
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct Hashtable
{
    Entry** buckets;
    int capacity;
} Hashtable;

Hashtable* ht_create(int size);
void ht_destroy(Hashtable* ht);
int ht_put(Hashtable* ht, int value);
int contain_value(Hashtable* ht, int value);
void printTable(Hashtable* ht);

#endif