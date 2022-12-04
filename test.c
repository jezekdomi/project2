#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h> // sqrtf
#include <limits.h> // INT_MAX
#include <string.h>

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
        fprintf(stderr, "obj was NULL\n");
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

void print_clusters(struct cluster_t *carr, int narr)
{
    printf("Clusters:\n");
    for (int i = 0; i < narr; i++)
    {
        printf("cluster %d: ", i);
        print_cluster(&carr[i]);
    }
}

int main(int argc, char const *argv[])
{
    (void) argc; (void) argv;

    struct cluster_t *clusters;

    FILE *f = fopen("objekty.txt", "r");
    int num_of_obj;

    if (fscanf(f, "count=%d", &num_of_obj) != 1)
    {
        fprintf(stderr, "invalid input\n");
    }
    
    printf("num_of_objects: %d\n", num_of_obj);

    clusters = malloc(num_of_obj* sizeof(struct cluster_t));
    if (clusters == NULL)
    {
        fprintf(stderr, "no space for clusters\n");
        return 0;
    }

    for (int i = 0; i < num_of_obj; i++)
    {
        init_cluster(&clusters[i]/* &(*arr)[i] */, 1);

        fscanf(f, "%d %f %f", &clusters[i].obj->id, &clusters[i].obj->x, /*&(*arr)[i]*/&clusters[i].obj->y);

        printf("cluster i (%d) id: %d\n", i, clusters[i].obj->id);

        // print_cluster(&(clusters[i]));
    }

    // print_clusters(clusters, num_of_obj);

    // clusters = malloc(2 * sizeof(struct cluster_t)); // zakomentovat pro ver1

    // init_cluster(&(clusters[0]), 2); // ver1
    // init_cluster(&(clusters[1]), 1); // ver1    

    // clusters[0].obj[0].id = 1;
    // clusters[0].obj[0].x = 10;
    // clusters[0].obj[0].y = 100;
    // clusters[0].size = 1;

    // clusters[0].obj[1].id = 2;
    // clusters[0].obj[1].x = 20;
    // clusters[0].obj[1].y = 200;
    // clusters[0].size = 2;

    // clusters[1].obj[0].id = 3;
    // clusters[1].obj[0].x = 30;
    // clusters[1].obj[0].y = 300;
    // clusters[1].size = 1;

    // print_cluster(&(clusters[0])); // ver1
    // print_cluster(&(clusters[1])); // ver1

    // free((*clusters).obj); // ver1
    // free((clusters[1]).obj); // ver1

    for (int i = 0; i < num_of_obj; i++)
    {
        free(clusters[i].obj);
    }
    free(clusters);

    return 0;
}