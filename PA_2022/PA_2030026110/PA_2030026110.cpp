#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXVEX 100
////Define the adjMatrix size
#define inf 32767
////Define infinity

using namespace std;

typedef struct VexNode
{
    char num;
    VexNode* pred;
    int color;
    int discoveryTime;
    int low;
    int type;
    int key;
}VexNode;

typedef struct Edge
{
    int weight;
    int start;
    int end;
}Edge;

typedef struct Graph
{
    VexNode vex[MAXVEX];
    vector<Edge> edge;
    int arc[MAXVEX][MAXVEX] = {0};
    int vexnum, edgenum;
}Graph;

Graph initGraph(string fileName) {
    ifstream fileStream;
    Graph graph;
    char c;
    fileStream.open(fileName);
	////Get the file
    int vexNum, edgeNum;
    fileStream >> vexNum >> edgeNum;
    ////Read the vexnum and edgenum
    graph.vexnum = vexNum;
    graph.edgenum = edgeNum;
    for (int i = 0; i < vexNum; i++) {
        graph.vex[i].num = i;
        graph.vex[i].pred = NULL;
        graph.vex[i].color = 0;
        graph.vex[i].type = i;
    }
    for (int i = 0; i < edgeNum; i++) {
        int edgeStart, edgeEnd;
        int edgeWeight;
        fileStream >> edgeStart >> c >> edgeEnd >> c >> edgeWeight;
		////Read the adjMatrix
        graph.arc[edgeStart][edgeEnd] = graph.arc[edgeEnd][edgeStart] = edgeWeight;
        graph.edge.push_back(Edge { edgeWeight,edgeStart,edgeEnd });
    }
    return graph;
}

void BiccVist(Graph* graph, int i, int time, stack<Edge>* stack, string* articulationPoint, vector<string>* Biccs) {
    graph->vex[i].color = 1;
    graph->vex[i].low = graph->vex[i].discoveryTime = ++time;
    int childs = 0;
    for (int j = 0; j < graph->vexnum; j++) {
        if (graph->arc[i][j] != 0) {
            if (graph->vex[j].color == 0) {
                childs++;
				//implict init the dfs structure to get the child
                Edge edge = { graph->arc[i][j], i, j };
                stack->push(edge);
                graph->vex[j].pred = &graph->vex[i];
				BiccVist(graph, j, time, stack, articulationPoint, Biccs);
                if (graph->vex[i].pred == NULL) {
                    if (childs >= 2) {
						//If the graph init tree structure root have more than 2 childs, it is a articulation point
                        string Bicc = "";
                        *articulationPoint = *articulationPoint + "Vertex " + to_string(graph->vex[i].num) + " ";
						//Get the information of the stack to the articulation point and put it in to the Biccs vector
                        while (stack->top().start != i) {
                            Bicc += to_string(stack->top().start) + "--" + to_string(stack->top().end) + " ";
                            stack->pop();
                        }
                        Bicc += to_string(stack->top().start) + "--" + to_string(stack->top().end);
                        stack->pop();
                        Biccs->push_back(Bicc);
                    }
                }
                else if (graph->vex[j].low >= graph->vex[i].discoveryTime) {
					string Bicc = "";
                    *articulationPoint = *articulationPoint + "Vertex " + to_string(graph->vex[i].num) + " ";
                    while (stack->top().start != i) {
                        Bicc += to_string(stack->top().start) + "--" + to_string(stack->top().end) + " ";
                        stack->pop();
                    }
                    Bicc += to_string(stack->top().start) + "--" + to_string(stack->top().end);
                    stack->pop();
                    Biccs->push_back(Bicc);
                }
            }
            else if (graph->vex[i].pred != NULL && graph->vex[j].num != graph->vex[i].pred->num && graph->vex[j].color != 2) {
                Edge edge = { graph->arc[i][j], i, j };
                stack->push(edge);
				//update the low value
                if (graph->vex[j].color == 1) {
                    if (graph->vex[j].low < graph->vex[i].low) {
                        graph->vex[i].low = graph->vex[j].low;
                    }
                }
            }
        }
    }
    graph->vex[i].color = 2;
}

void Bicc(Graph* graph, string* articulationPoint, vector<string>* Biccs) {
    int time = 0;
    stack<Edge> stack;
	//In undictract graph, only exist the tree edge, backedge. so if the color is not black we should add it to the stack.
    for (int i = 0; i < graph->vexnum; i++) {
        if (graph->vex[i].color == 0) {
			BiccVist(graph, i, time, &stack, articulationPoint, Biccs);
        }
    }
    string Biccstr = "";
    for (int i = stack.size(); i >0 ; i--) {
        Biccstr += to_string(stack.top().start) + "--" + to_string(stack.top().end) + " ";
        stack.pop();
    }
    Biccs->push_back(Biccstr);
}

int Find(Graph* graph, int num) {
    //return the class of the vex
    return graph->vex[num].type;
}

void Merge(Graph* graph, int start, int end) {
	//merge the class of the vex
    int tempType = graph->vex[end].type;
    for (int i = 0; i < graph->vexnum; i++){
        if (graph->vex[i].type == tempType) {
            graph->vex[i].type = graph->vex[start].type;
        }
    }
}
bool mycomp(Edge a, Edge b) {
	//our self define the sort function, use to get the min edge
    return (a.weight < b.weight);
}



void Kruskal(Graph* graph, string* minimumST) {
	//use stl sort to get the min edge
    std::sort(graph->edge.begin(), graph->edge.end(), mycomp);
    for (int i = 0; i < graph->edgenum; i++) {
        Edge tempEdge = graph->edge[i];
        if (Find(graph, tempEdge.start) != Find(graph, tempEdge.end)) {
            *minimumST += to_string(tempEdge.start) + "--" + to_string(tempEdge.end) + " ";
            Merge(graph, tempEdge.start, tempEdge.end);
        }
    }
}

void Dijkstra(Graph* graph, string* shotST) {
    for (int i = 0; i < graph->vexnum; i++) {
        graph->vex[i].color = 0;
        graph->vex[i].pred = NULL;
        graph->vex[i].key = inf;
        // maximize the distance
    }
    graph->vex[0].key = 0;
    graph->vex[0].pred = NULL;
    for (int i = 0; i < graph->vexnum; i++) {
        int minn = inf, minx=-1;
        for (int j = 0; j < graph->vexnum; j++) {
            //implict get the PQ use array structure with O(n^2)
            if (graph->vex[j].key < minn && graph->vex[j].color == 0) {
                minn = graph->vex[j].key;
                minx = j;
            }
        }
        for (int j = 0; j < graph->vexnum; j++) {
            if (graph->arc[minx][j] != 0 && graph->vex[j].color == 0) {
                if (graph->vex[minx].key + graph->arc[minx][j] < graph->vex[j].key) {
                    graph->vex[j].key = graph->vex[minx].key + graph->arc[minx][j];
                    graph->vex[j].pred = &graph->vex[minx];
                }
            }
        }
        graph->vex[minx].color = 2;
    }
    for (int i = 1; i < graph->vexnum; i++) {
        *shotST += to_string(graph->vex[i].pred->num) + "--" + to_string(graph->vex[i].num) + " ";
    }
}

int main() {
    cout << "***************" << std::endl;
    cout << "Input the file name:" << std::endl;
    string fileName;
    while (cin >> fileName) {
        // In cpp input stream if not EOF(ctrl+z) will be true.
        Graph allGraph = initGraph(fileName);
        cout << "***************" << std::endl;
        cout << "1. The articulation point(s) found in the given graph is/are:" << std::endl;
		string articulationPoint="";
		vector<string> Biccs;
		//Use String and vector to store the result
		Bicc(&allGraph, &articulationPoint, &Biccs);
		cout << articulationPoint << endl;
        cout << "The biconnected component(s) found in the given graph is/are:" << std::endl;
        for (int i = 0; i < Biccs.size(); i++) {
            cout << Biccs[i] << endl;
        }
        cout << "***************" << std::endl;
        cout << "2. The following are the edges in the constructed MST:" << std::endl;
        string minimumST="";
        Kruskal(&allGraph, &minimumST);
        cout << minimumST << endl;
        cout << "***************" << std::endl;
        cout << "3. The following are the edges in the constructed SPT:" << std::endl;
        string shotST = "";
        Dijkstra(&allGraph, &shotST);
        cout << shotST << endl;
        cout << "***************" << std::endl;
        cout << "Input the file name:" << std::endl;
    }
}