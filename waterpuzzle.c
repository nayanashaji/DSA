#include <stdio.h>
#include <stdlib.h>

struct State {
    int c1, c2, c3;
};

int goal;
int visited[21][21][21];

int isGoal(struct State s) {
    return (s.c2 == goal || s.c3 == goal);
}

void printState(struct State s) {
    printf("(%d, %d, %d)\n", s.c1, s.c2, s.c3);
}

struct State pour(struct State s, int from, int to, int cap[]) {
    int amt[3] = {s.c1, s.c2, s.c3};
    int pourAmt = (amt[from] < cap[to] - amt[to]) ? amt[from] : cap[to] - amt[to];
    amt[from] -= pourAmt;
    amt[to] += pourAmt;
    struct State newState = {amt[0], amt[1], amt[2]};
    return newState;
}

void BFS(struct State start, int cap[]) {
    struct State queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.c1][start.c2][start.c3] = 1;
    printf("Exploring states:\n");
    printState(start);

    while (front < rear) {
        struct State current = queue[front++];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    struct State next = pour(current, i, j, cap);
                    if (!visited[next.c1][next.c2][next.c3]) {
                        visited[next.c1][next.c2][next.c3] = 1;
                        if (isGoal(next)) {
                            printf("Goal reached:\n");
                            printState(next);
                            return;
                        }
                        queue[rear++] = next;
                        printState(next);
                    }
                }
            }
        }
    }
    printf("No solution found.\n");
}

int main() {
    int cap[3];
    struct State start;
    printf("Enter capacities of three containers: ");
    scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);
    printf("Enter initial state (C1 C2 C3): ");
    scanf("%d %d %d", &start.c1, &start.c2, &start.c3);
    printf("Enter goal amount: ");
    scanf("%d", &goal);
    BFS(start, cap);
    return 0;
}

