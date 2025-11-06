#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src - 1];
    graph->adjLists[src - 1] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest - 1];
    graph->adjLists[dest - 1] = newNode;
}

void DFSUtil(struct Graph* graph, int vertex) {
    graph->visited[vertex - 1] = 1;
    printf("%d ", vertex);
    struct Node* temp = graph->adjLists[vertex - 1];
    while (temp) {
        if (!graph->visited[temp->vertex - 1])
            DFSUtil(graph, temp->vertex);
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex);
    printf("\n");
}

void BFS(struct Graph* graph, int startVertex) {
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;
    graph->visited[startVertex - 1] = 1;
    queue[rear++] = startVertex;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        struct Node* temp = graph->adjLists[currentVertex - 1];
        while (temp) {
            if (!graph->visited[temp->vertex - 1]) {
                graph->visited[temp->vertex - 1] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(queue);
}

void displayGraph(struct Graph* graph) {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d -> ", i + 1);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    displayGraph(graph);
    printf("Enter start vertex: ");
    scanf("%d", &start);
    DFS(graph, start);
    BFS(graph, start);
    return 0;
}
