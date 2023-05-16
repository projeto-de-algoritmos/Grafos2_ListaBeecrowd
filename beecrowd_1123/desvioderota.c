#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define INF INT_MAX

int n, m, c, k;
int grafo[1010][1010];
int custo[1010];

int fila[1010], ini, fim;

void infinito(){
    int i, j;
    for(i=0; i<=n; i++){
        custo[i]= INF;
        for(j=0; j<=n; j++) grafo[i][j]=INF;
    }
    ini = 0;
    fim = 0;
}

void push(int x) {
    if (fim < 1010) {
        fila[fim++] = x;
    }
}

int front() {
    return fila[ini];
}

void pop() {
    ini++;
}

int empty() {
    return ini == fim;
}

int dijkstra(int ori, int dest){
    int i, j;
    custo[ori] = 0;
    push(ori);
    while(!empty()){
        i = front();
        pop();
        for(j=0; j<n; j++){
            if(grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]){
                custo[j] = custo[i] + grafo[i][j];
                push(j);
            }
        }
    }
    return custo[dest];
}

int main (){
    while (scanf("%d %d %d %d", &n, &m, &c, &k), (n||m||c||k)){
        infinito(); 
        int i, u, v, p;
        for(i=1; i<=m; i++){
            scanf("%d %d %d", &u, &v, &p);
            if(u>=c && v>=c){
                grafo[u][v]=p;
                grafo[v][u]=p;
            }
            if(u>=c && v<c) grafo[u][v]=p; 
            if(u<c && v>=c) grafo[v][u]=p; 
            if(u<c && v<c && abs(u-v)==1){
                grafo[u][v]=p;
                grafo[v][u]=p;
            }
        }
        printf("%d\n", dijkstra(k, c-1)); 
    }
    return 0;
}
