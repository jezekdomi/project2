#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h> // sqrtf
#include <limits.h> // INT_MAX

struct obj_t {
    int id;
    float x;
    float y;
};

struct cluster_t {
    int size;
    int capacity;
    struct obj_t *obj;
};

void init_cluster(struct cluster_t *c, int cap)
{
    assert(c != NULL);
    assert(cap >= 0);

    // TODO
    c->obj = malloc(cap * sizeof(struct obj_t));
    if (c->obj == NULL)
    {
        c->capacity = 0;
    }
    else
    {
        c->capacity = cap;
    }
    c->size = 0;
}

void print_cluster(struct cluster_t *c)
{
    // TUTO FUNKCI NEMENTE
    for (int i = 0; i < c->size; i++)
    {
        if (i) putchar(' ');
        printf("%d[%g,%g]", c->obj[i].id, c->obj[i].x, c->obj[i].y);
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    struct cluster_t *clusters;

    clusters = malloc(2 * sizeof(struct cluster_t));

    init_cluster(&clusters[0], 2);
    init_cluster(&clusters[1], 1);

    clusters[0].obj[0].id = 1;
    clusters[0].obj[0].x = 10;
    clusters[0].obj[0].y = 100;
    clusters[0].size = 1;

    clusters[0].obj[1].id = 2;
    clusters[0].obj[1].x = 20;
    clusters[0].obj[1].y = 200;
    clusters[0].size = 2;

    clusters[1].obj[0].id = 3;
    clusters[1].obj[0].x = 30;
    clusters[1].obj[0].y = 300;
    clusters[1].size = 1;

    print_cluster(&clusters[0]);

    print_cluster(&clusters[1]);

    return 0;
}