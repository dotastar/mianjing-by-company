#ifndef SLAB_H
#define SLAB_H
void slab_init();
int slab_find_class(int size);
void* slab_alloc(int size);
void slab_free(void *p);
#endif
