//-----------------------TestCode---------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_VEX_NUM 5
typedef struct gp {
    int vexArr[MAX_VEX_NUM];
    int arcArr[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexNum, arcNum;
} Graph;

struct {
    int vex, lowestCost;
} closedge[MAX_VEX_NUM];


int minimumEdge(Graph gp);

void initialClosedgeArray(Graph *g, int startVex);

void prim3(Graph gp, int i);

void prim2(Graph g, int u) {
    initialClosedgeArray(&g, u);
    //n-1 edges.
    for (int k = 1; k < g.vexNum; k++) {
        int v = minimumEdge(g);
        //Print the smallest-cost edge.
        printf("%d-%d ", closedge[v].vex, v);
        closedge[v].lowestCost = 0;

        for (int j = 0; j < g.vexNum; j++) {
            if (g.arcArr[v][j] < closedge[j].lowestCost) {
                closedge[j].lowestCost = g.arcArr[v][j];
                closedge[j].vex = v;
            }
        }
    }
}

void initialClosedgeArray(Graph *g, int startVex) {
    for (int i = 0; i < (*g).vexNum; i++) {
        closedge[i].vex = startVex;
        if (i == startVex) {
            //(U-U) is be set to 0;
            closedge[startVex].lowestCost = 0;
        } else {
            closedge[i].lowestCost = (*g).arcArr[startVex][i];
        }
    }
}

int minimumEdge(Graph gp) {
    int min = INT_MAX, v;
    for (int j = 0; j < gp.vexNum; j++) {
        if (closedge[j].lowestCost < min && closedge[j].lowestCost != 0) {
            min = closedge[j].lowestCost;
            v = j;
        }
    }
    return v;
}

/**
 * A wrong algorithm from the book!!!
 * @param g
 * @param u
 */
void prim(Graph g, int u) {
    for (int v = 0; v < g.vexNum; v++) {
        if (v != u) {
            closedge[v].vex = u;
            closedge[v].lowestCost = g.arcArr[u][v];
        } else {
            closedge[u].lowestCost = INT_MAX;
        }
        printf("(%d,%d)", closedge[v].vex, closedge[v].lowestCost);
    }
    printf("\n\n\n");
    //n-1 edges.
    for (int k = 1; k < g.vexNum; k++) {
        int min = closedge[k].lowestCost;
        int v = k;
        for (int j = 0; j < g.vexNum; j++) {
            if (closedge[j].lowestCost < min) {
                min = closedge[j].lowestCost;
                v = j;
//                printf("v=%d", v);
            }
        }
        printf("%d-%d ", closedge[v].vex, v);
        closedge[v].lowestCost = INT_MAX;

        for (int j = 0; j < g.vexNum; j++) {
            if (g.arcArr[v][j] < closedge[j].lowestCost) {
                closedge[j].lowestCost = g.arcArr[v][j];
                closedge[j].vex = v;
            }
        }
    }
}

void main() {
    Graph graph;
    for (int i = 0; i < MAX_VEX_NUM; i++) {
        graph.vexArr[i] = i;
//        printf("graph.vexArr[%d]=%d\n", i, graph.vexArr[i]);
    }
    graph.vexNum = MAX_VEX_NUM;
    int tempArr[MAX_VEX_NUM][MAX_VEX_NUM] = {
            INT_MAX, 50, INT_MAX, 40, 20,
            50, INT_MAX, 10, INT_MAX, INT_MAX,
            INT_MAX, 10, INT_MAX, 20, 30,
            40, INT_MAX, 20, INT_MAX, INT_MAX,
            20, INT_MAX, 30, INT_MAX, INT_MAX
    };
    for (int i = 0; i < MAX_VEX_NUM; ++i) {
        for (int j = 0; j < MAX_VEX_NUM; ++j) {
            graph.arcArr[i][j] = tempArr[i][j];
//            printf("tempArr[i][j]=%d ", tempArr[i][j]);
        }
//        printf("\n");
    }
//    prim2(graph, 0);
    prim3(graph, 3);
}

/**
 * The same logic as prim2.
 * This is just for practice.
 * @param gp
 * @param u
 */
void prim3(Graph gp, int u) {
    initialClosedgeArray(&gp, u);
    for (int i = 0; i < gp.vexNum - 1; ++i) {
        int v = minimumEdge(gp);
        printf("(%d-%d)", closedge[v].vex, v);
        closedge[v].lowestCost = 0;

        for (int index = 0; index < gp.vexNum; ++index) {
            if(gp.arcArr[v][index] < closedge[index].lowestCost) {
                closedge[index].lowestCost = gp.arcArr[v][index];
                closedge[index].vex = v;
            }
        }
    }
}
