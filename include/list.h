#ifndef __LIST__H
#define __LIST__H

struct list {
        void* contents;
        size_t elem_size;
        
        unsigned int max;
        unsigned int size;
};

struct list* list_create(unsigned int initial_max, size_t elem_size);

void list_push(struct list* l, const void* src);

void list_pop(struct list* l, void* dest);

void list_set(struct list* l, unsigned int index, const void* src);

void list_get(struct list* l, unsigned int index, void* dest);

void list_clear(struct list* l);

void list_destroy(struct list* l);

#endif