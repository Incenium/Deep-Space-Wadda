#include <stdlib.h>

#include "list.h"
#include "debug.h"

#define list_offset(L, I) L->contents + (I) * L->elem_size

struct list* list_create(unsigned int initial_max, size_t elem_size)
{
        struct list* l = malloc(sizeof(struct list*));
        check_mem(l);

        l->elem_size = elem_size;

        l->contents = calloc(initial_max, elem_size);
        check_mem(l->contents);

        l->max = initial_max;
        l->size = 0;

        return l;

error:
        return NULL;
}

void list_push(struct list* l, const void* src)
{
        check(l != NULL, "Cannot pass a NULL struct list pointer to list_push");
        check(src != NULL, "Cannot pass a NULL pointer to list_push");

        // equivalent to last(l) + 1
        unsigned int index = l->size;
        if (index > l->max - 1){
                // the array doubles in size every time we need to reallocate
                l->max *= 2;
                l->contents = realloc(l->contents, l->max * l->elem_size);
                check_mem(l->contents);
        }

        memcpy(list_offset(l, index), src, l->elem_size);

        l->size++;

error:
        return;
}

void list_pop(struct list* l, void* dest)
{
        check(l != NULL, "Cannot pass a NULL struct list pointer to list_pop");
        check(dest != NULL, "Cannot pass a NULL pointer for dest to list_pop");
        check(l->size > 0, "Cannot pop item from empty list");

        void* end = list_offset(l, l->size - 1);
        memcpy(dest, end, l->elem_size);
        memset(end, 0, l->elem_size);

        l->size--;

        if (l->size < l->max / 2){
                l->max /= 2;
                l->contents = realloc(l->contents, l->max * l->elem_size);
                check_mem(l->contents);
        }

error:
        return;
}

void list_set(struct list* l, unsigned int index, const void* src)
{
        check(l != NULL, "Cannot pass a NULL struct list pointer to list_set");

        check(index < l->size, "Cannot access list out of bounds");
        check(src != NULL, "Cannot pass a NULL pointer for src to list_set");

        memcpy(list_offset(l, index), src, l->elem_size);

error:
        return;
}

void list_get(struct list* l, unsigned int index, void* dest)
{
        check(l != NULL, "Cannot pass a NULL struct list pointer to list_get");
        check(index < l->size, "Cannot access list out of bounds");
        check(dest != NULL, "Cannot pass a NULL pointer for dest to list_get");

        memcpy(dest, list_offset(l, index), l->elem_size);

error:
        return;
}

void list_clear(struct list* l)
{
        for (unsigned int i = 0; i < l->size; i++)
                memset(list_offset(l, i), 0, l->elem_size);

        l->size = 0;
}

void list_destroy(struct list* l)
{
        free(l->contents);
        free(l);

        l = NULL;
}