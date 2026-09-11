#include <stdio.h>
#include <malloc.h>
#include "hashtable.h"

static int ht_hash(Hashtable* ht, int value)
{
    int index = value % ht->capacity;
    return index;
}

Hashtable* ht_create(int size)
{
    if (size <= 0) size = 10;
    Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
    if (ht == NULL)
    {
        fprintf(stderr, "ht malloc failed");
        return NULL;
    }
    ht->capacity = size;
    ht->buckets = (Entry**)calloc(size, sizeof(Entry));
    if (ht->buckets == NULL)
    {
        fprintf(stderr, "bucket calloc failed");
        free(ht);
        return NULL;
    }
    return ht;
}

void ht_destroy(Hashtable* ht)
{
    if (ht == NULL)
    {
        fprintf(stderr,"empty hastable");
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

int ht_put(Hashtable* ht, int value)
{
    if (contain_value(ht, value))
    {
        return 0;
    }

    int index = ht_hash(ht, value);
    Entry* node = (Entry*)malloc(sizeof(Entry));
    if (node == NULL)
    {
        fprintf(stderr, "node malloc failed");
        free(node);
        return 0;
    }
    node->key = node->value = value;
    node->next = ht->buckets[index];
    ht->buckets[index] = node;
    return 1;
}

int contain_value(Hashtable* ht, int value)
{
    if (ht == NULL)
    {
        fprintf(stderr,"empty hastable");
        return 0;
    }
    int index = ht_hash(ht, value);
    Entry* current = ht->buckets[index];
    while (current != NULL)
    {
        if (current->key == value)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printTable(Hashtable* ht)
{
    if (ht == NULL)
    {
        fprintf(stderr,"empty hastable");
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