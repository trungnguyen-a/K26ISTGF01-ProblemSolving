#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "hashtable.h"

static int ht_hash(int key, int size)
{
    if (size <= 0)
    {
        return 0;
    }
    int hash_value = key % size;
    if (hash_value < 0)
    {
        hash_value = hash_value + size;
    }
    return hash_value;
}

Hashtable* ht_create(int size)
{
    if (size <= 0)
    {
        size = 10;
    }

    Hashtable* ht = (Hashtable*)(malloc(sizeof(Hashtable)));
    if (ht == NULL)
    {
        fprintf(stderr, "Failed to allocate HashTable");
        return NULL;
    }
    ht->capacity = size;
    ht->buckets = (Entry**)calloc(size, sizeof(Entry*));
    if (ht->buckets == NULL)
    {
        fprintf(stderr, "Failed to allocate buckets");
        free(ht);
        return NULL;
    }
    return ht;
}

void ht_destroy(Hashtable* ht)
{
    if (ht == NULL)
    {
        printf("NULL HashTable");
        return;
    }
    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry* current = ht->buckets[i];
        while (current != NULL)
        {
            Entry* temp = current;
            // current = current->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}

void ht_put(Hashtable* ht, int key)
{
    if (ht == NULL)
    {
        printf("Failed to allocate HashTable");
        return;
    }
    int index = ht_hash(key, ht->capacity);
    Entry* current = ht->buckets[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value+=1;
            return;
        }
        // current = current->next;
    }

    Entry* node = (Entry*)malloc(sizeof(Entry));
    if (node == NULL)
    {
        fprintf(stderr, "allocated memory failed");
        return;
    }
    node->key = key;
    node->value = 1;
    // node->next = ht->buckets[index];
    ht->buckets[index] = node;
}

int ht_get_most_repeat_key(Hashtable* ht)
{
    if (ht == NULL)
    {
        printf("NULL HashTable");
        return -1;
    }
    int max = 0;
    for (size_t i = 0; i < ht->capacity; i++)
    {
        if (ht->buckets[i] == NULL) continue;
        max = (ht->buckets[i]->value > max)? ht->buckets[i]->key : max;
    }
    return max;
}

int ht_containsValue(Hashtable* ht, int value)
{
    
}

void ht_printEntries(Hashtable* ht)
{
    if (ht == NULL)
    {
        printf("NULL HashTable");
        return;
    }
    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry* current = ht->buckets[i];
        if (current == NULL) continue;
        printf("Bucket[%d]: ", i);
        printf("(%d = %d) ", current->key, current->value);
        printf("\n");
    }
}
