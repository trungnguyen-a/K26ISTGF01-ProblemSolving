#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Entry
{
    int key;
    int value;
} Entry;

typedef struct Hashtable
{
    Entry** buckets;
    int capacity;
} Hashtable;

Hashtable* ht_create(int size);
void ht_destroy(Hashtable* ht);
void ht_put(Hashtable* ht, int key);
int ht_get_most_repeat_key(Hashtable* ht);
void ht_printEntries(Hashtable* ht);

#endif