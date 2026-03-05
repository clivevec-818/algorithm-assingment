#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26
int graph[MAX][MAX];
int transpose[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
char vertices[MAX];
int vertexCount = 0;
void addVertex(char v) {
for(int i = 0; i < vertexCount; i++)
if(vertices[i] == v)
return;
vertices[vertexCount++] = v;}
int getIndex(char v) {
for(int i = 0; i < vertexCount; i++)
if(vertices[i] == v)
return i;
return -1;}
void addEdge(char u, char v) {
addVertex(u);
addVertex(v);
int i = getIndex(u);
int j = getIndex(v);
graph[i][j] = 1;}
void fillOrder(int v) {
visited[v] = 1;
for(int i = 0; i < vertexCount; i++) {
if(graph[v][i] && !visited[i])
fillOrder(i);}
stack[++top] = v;}
void transposeGraph() {
for(int i = 0; i < vertexCount; i++)
for(int j = 0; j < vertexCount; j++)
transpose[i][j] = graph[j][i];}
void dfsSCC(int v, int *component, int *compSize) {
visited[v] = 1;
component[(*compSize)++] = v;
for(int i = 0; i < vertexCount; i++) {
if(transpose[v][i] && !visited[i])
dfsSCC(i, component, compSize);}}
void findSCCs() {
FILE *fp = fopen("scc_results.txt", "w");
for(int i = 0; i < vertexCount; i++)
visited[i] = 0;
for(int i = 0; i < vertexCount; i++)
if(!visited[i])
fillOrder(i);
transposeGraph();
for(int i = 0; i < vertexCount; i++)
visited[i] = 0;
printf("Strongly Connected Components (SCCs)\n");
printf("Using Kosaraju’s Algorithm\n");
printf("------------------------------------\n");
fprintf(fp, "Strongly Connected Components (SCCs)\n");
fprintf(fp, "Using Kosaraju’s Algorithm\n");
fprintf(fp, "------------------------------------\n");
int sccNumber = 1;
while(top >= 0) {
int v = stack[top--];
if(!visited[v]) {
int component[MAX];
int compSize = 0;
dfsSCC(v, component, &compSize);
printf("SCC %d: { ", sccNumber);
fprintf(fp, "SCC %d: { ", sccNumber);
for(int i = 0; i < compSize; i++) {
printf("%c", vertices[component[i]]);
fprintf(fp, "%c", vertices[component[i]]);
if(i != compSize - 1) {
printf(", ");
fprintf(fp, ", ");}}
printf(" }\n");
fprintf(fp, " }\n");
sccNumber++;}}
printf("\nTime Complexity: O(V + E)\n");
fprintf(fp, "\nTime Complexity: O(V + E)\n");
fclose(fp);}
int main() {
for(int i = 0; i < MAX; i++)
for(int j = 0; j < MAX; j++)
graph[i][j] = 0;
addEdge('a','b');
addEdge('c','a');
addEdge('b','c');
addEdge('b','d');
addEdge('c','e');
addEdge('c','d');
addEdge('d','e');
addEdge('f','d');
addEdge('e','f');
addEdge('f','g');
addEdge('g','e');
addEdge('h','f');
ddEdge('g','h');
findSCCs();
return 0;}
