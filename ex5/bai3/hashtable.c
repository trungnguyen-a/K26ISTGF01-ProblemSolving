#include <stdio.h>
#include <malloc.h>
#include "hashtable.h"

static int ht_hash(Hashtable* ht, int value)
{
    int index = value % ht->capacity;
    if (index < 0)
    {
        index *= -1;
    }
    return index;
}

Hashtable* ht_create(int size)
{
    if (size <= 0)
    {
        size = 10;
    }
    
    Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
    if (ht == NULL)
    {
        fprintf(stderr, "hashtable allocated failed");
        return NULL;
    }
    
    ht->capacity = size;
    ht->buckets = (Entry**)calloc(size, sizeof(Entry));
    if (ht->buckets == NULL)
    {
        fprintf(stderr, "bucket allocated failed");
        free(ht);
        return NULL;
    }

    return ht;
}

int ht_put(Hashtable* ht, int value)
{
    if (ht_contain(ht, value))
    {
        return 0;
    }
    
    int index = ht_hash(ht, value);
    Entry* node = (Entry*)malloc(sizeof(Entry));
    if (node == NULL)
    {
        fprintf(stderr, "node allocated failed");
        return 0;
    }
    node->value = value;
    node->next = ht->buckets[index];
    ht->buckets[index] = node;

    return 1;
}

int ht_contain(Hashtable* ht, int value)
{
    if (ht == NULL)
    {
        fprintf(stderr, "hashtable null");
        return 0;
    }
    
    int index = ht_hash(ht, value);
    Entry* current = ht->buckets[index];
    while (current != NULL)
    {
        if (current->value == value)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int ht_get(Hashtable*ht, int value)
{
    if (ht == NULL)
    {
        fprintf(stderr, "hashtable null");
        return 0;
    }

    if (ht_contain(ht, value))
    {
        return value;
    }
    
    return 0;
}

void print_table(Hashtable* ht)
{
    if (ht == NULL)
    {
        fprintf(stderr, "hashtable null");
        return;
    }
    
    for (size_t i = 0; i < ht->capacity; i++)
    {
        printf("Bucket[%d]: ", i);
        Entry* current = ht->buckets[i];
        while (current != NULL)
        {
            printf("( %d )", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void ht_destroy(Hashtable* ht)
{
    if (ht == NULL)
    {
        fprintf(stderr, "hashtable null");
        return;
    }

    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry* current = ht->buckets[i];
        while (current != NULL)
        {
            Entry* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}