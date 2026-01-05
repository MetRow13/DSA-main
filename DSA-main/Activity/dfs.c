#include <stdio.h>
#define MAX 9

typedef struct node{
    int data;
    struct node * link;
}*ptr, Node;

#define VISITED -1
#define UNVISITED 100
typedef ptr Graph[MAX];
typedef int vertex;

void dfs(Graph G, vertex V , int mark[]){

}