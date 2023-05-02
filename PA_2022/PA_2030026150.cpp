#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// variables declaration.
// declare a set to store vertexes.
int vertex[50];

// used to store the number of point.
int vertex_Num = 0;
// used to store the number of value.
int edge_Num = 0;
int edge_Num_d = 0;

// declare some global variables.
char color[50];
// used to store low value of vertex.
int low[50];
// used to store discover time of vertex.
int d[50];
// used to store discover time.
int time = -1;

// used to store the vertex and its weight.
// the form just like input file.
int graph[50][3];
int pred[50];
//int father[50];

// as stack of S and Bicomp.
int S[50][2];
int Bicomp[50][2];
// used to store the size of S and Bicomp stack.
int ls = 0, lb = 0;

// used to store the graph.
int weight_edge[50][50];
// used to store edges' vertex and its weight.
struct edge {
    int u;
    int v;
    int w;
};
struct edge e[50];



// functions declaration.
bool cmp(const edge &a, const edge &b);
int min(int a,int b);
void ReArtPt(int v);
void ReArtPt_BC(int v);
int findPartents(int x);
void MST();
void SPT(int vertex_Num);


// function implementation.
// used to do sorting.
bool cmp(const edge &a, const edge &b){
	return a.w < b.w;
}


// implementation funcition min,
// to find min number between a and b.
int min(int a, int b){
	return a < b ? a : b;
}


// used to find articulation point.
void ReArtPt(int v){
	// set current vertex as grey.
	color[v]='g';
	// increase low value and discover time of v.
	low[v] = d[v] = ++time;

	// start to scan all neighbor vertex of w.
	for(int i = 0; i < edge_Num_d; i++){
		if (graph[i][0] != v){
			// which means not v's neighbor.
			continue;
		}
		// let current w as neighbor of v.
		int w = graph[i][1];
		// check whether current neighbor has been visited.
		if(color[w] == 'w'){
			// set w's parent as v.
			pred[w] = v;
			// find articulation point recursively.
			ReArtPt(w);
			// check whether v is root of tree.
			if(pred[v] == -1){
				// which means v is root,
				// according to ovservation, check num of its child.
				int child_Num = 0;
				// scan all points in graph.
				for(int k = 0; k < vertex_Num; k++){
					// if k's parents is v, increase child_Num.
					if(pred[k] == v){
						child_Num++;
					}
				}
				if(child_Num > 1){
					// which means v is an articulation point.
					printf("Vertex: %d\n",v);
				}

			} else if(low[w] >= d[v]){
				printf("Vertex: %d\n", v);
			}
			// update low value by take min low value between v and w.
			low[v] = min(low[v], low[w]);
		} else if(w != pred[v]){
			// update low value by take min between low[v] and d[w].
			low[v] = min(low[v], d[w]);
		}	
	}
	// set color of vertex as black.
	// which means this vertex finish visit.
	color[v] = 'b';
	return;
}


// used to find biconnection component.
void ReArtPt_BC(int v){
	// set current vertex as grey.
	color[v]='g';
	// increase low value and discover time of v.
	low[v] = d[v] = ++time;

	// start to scan all neighbor vertex of w.
	for(int i = 0; i < edge_Num_d; i++){
		if (graph[i][0] != v){
			// which means not v's neighbor.
			continue;
		}
		// let current w as neighbor of v.
		int w = graph[i][1];
		// check whether current neighbor has been visited.
		if(color[w] == 'w'){
			// set w's parent as v.
			pred[w] = v;
			// push v-w into stack.
			// in order to output as small--big,
			// check scale of vertex.
			if(v < w){
				S[ls][0] = v;
				S[ls][1] = w;
				// increase the size of stack.
				ls++;
			} else {
				S[ls][0] = w;
				S[ls][1] = v;
				// increase the size of stack.
				ls++;
			}
			// find articulation point recursively.
			ReArtPt_BC(w);
			// check whether v is root of tree.
			if(pred[v] == -1){
				// which means v is root,
				// according to ovservation, check num of its child.
				int child_Num = 0;
				// scan all points in graph.
				for(int k = 0; k < vertex_Num; k++){
					// if k's parents is v, increase child_Num.
					if(pred[k] == v){
						child_Num++;
					}
				}
				if(child_Num > 1){
					// which means v is an articulation point.
					//printf("Vertex: %d\n",v);
					// set the stack as empty.
					lb = 0;
					// if there exists elements in stack.
					if(ls > 0){
						// swap v and w.
						if(v > w){
							int temp = v;
							v = w;
							w = temp;
						}
						// for top elements that S != vw,
						// pop edge from S and add to Bicomp.
						while(S[ls-1][0] != v || S[ls-1][1] != w){
							Bicomp[lb][0] = S[ls-1][0];
							Bicomp[lb][1] = S[ls-1][1];
							// increase size of Bicomp stack.
							lb++;
							// decrease size of S stack.
							ls--;
						}

						// still, the edge include articulation also poped.
						Bicomp[lb][0] = S[ls-1][0];
						Bicomp[lb][1] = S[ls-1][1];
						// increase size of Bicomp stack.
						lb++;
						// decrease size of S stack.
						ls--;
						// output Bicomp.
						if(lb > 0){
							for(int k = 0; k < lb; k++){
								printf("%d--%d ",Bicomp[k][0],Bicomp[k][1]);
							}
							printf("\n");
							// set the size of Bicomp stack as empty.
							lb = 0;
						}
					}

					// set the size of Bicomp stack as empty.
					lb = 0;
				}

			} else if(low[w] >= d[v]){
				//printf("Vertex: %d\n", v);
				// set the size of Bicomp stack as empty.
				lb = 0;
				if(ls > 0){
					if(v > w){
						int temp =v;
						v = w;
						w = temp;
					}
					// for top elements that S != vw,
					// pop edge from S and add to Bicomp.
					while(S[ls-1][0] != v || S[ls-1][1] != w){
						Bicomp[lb][0] = S[ls-1][0];
						Bicomp[lb][1] = S[ls-1][1];
						// increase size of Bicomp stack.
						lb++;
						// decrease size of S stack.
						ls--;
					}
					// pop edge from S and add it to Bicomp.
					Bicomp[lb][0] = S[ls-1][0];
					Bicomp[lb][1] = S[ls-1][1];
					// increase size of Bicomp stack.
					lb++;
					// decrease size of S stack.
					ls--;
					// output Bicomp from stack.
					if(lb > 0){
						for(int k = 0; k < lb; k++){
							printf("%d--%d ",Bicomp[k][0],Bicomp[k][1]);
						}
						printf("\n");
						// set the size of Bicomp as empty.
						lb = 0;
					}
				}
			}
			// update low value by take min low value between v and w.
			low[v] = min(low[v], low[w]);
		} else if(w != pred[v]){
			// update low value by take min between low[v] and d[w].
			low[v] = min(low[v], d[w]);
			if(d[w] < d[v]){
				// push v-w into stack.
				// in order to output as small--big,
				// check scale of vertex.
				if(v < w){
					S[ls][0] = v;
					S[ls][1] = w;
					// increase the size of stack.
					ls++;
				} else {
					S[ls][0] = w;
					S[ls][1] = v;
					// increase the size of stack.
					ls++;
				}
			}
		}	
	}
	// set color of vertex as black.
	// which means this vertex finish visit.
	color[v] = 'b';
	return;
}


// used to find the root of tree.
int findPartents(int x) {
	// initialize root variable as current input.
	int root = x;
	// once its parents is not root, find root recursively.
	while (pred[root] != root){
		root = pred[root];
	}
		
	// path compression.
	while (pred[x] != x) {
		int t = x;
		x = pred[x];
		pred[t] = root;
	}
	// reutrn the result.
	return root;
}


// used to generate minimum spinning tree.
void MST(){
	// use counter to store vertex that already add into MST.
	int counter = 0;
	// first, sort edges by their weight.
	sort(e, e + edge_Num, cmp);
	// initialize all vertex, create set.
	for (int i = 0; i < 30; i++){
		pred[i] = i;
	}
	for (int i = 0; i < edge_Num; i++) {
		// find parents of two vertex.
		int pred_u = findPartents(e[i].u);
		int pred_v = findPartents(e[i].v);
		// once their parents not same,
		// push edge u--v as MST.
		if (pred_u != pred_v) {
			pred[pred_v] = pred_u;
			// increase the counter.
			counter++;
			// print out the edges, which is safe path.
			printf("%d--%d ",e[i].u, e[i].v);
			if(counter == vertex_Num - 1){
				break;
			}
		}
	}
	// if counter != num-1,
	// it proves that there exists vertex disconnected.
	return;
}


void SPT(int vertex_Num) {

	// min used to store min distance, first set as inf.
    int min = 99999;
	int dis[50], vertex[101], u;
	// let dis array store weight of edges.
    for (int i = 0; i < vertex_Num; i++) {
        dis[i] = weight_edge[0][i];
    }
	// initialize vertex array,
	// let all point as 0 and all their parents as 0.
    for (int j = 0; j < vertex_Num; j++) {
        vertex[j] = 0;
        pred[j] = 0;
    }
	// let first vertex as 1,
    vertex[0] = 1;
	// process all vertices.
	// extract min u as root.
    for (int k = 0; k < vertex_Num - 1; k++) {
        min = 99999;
        for (int w = 1; w < vertex_Num; w++) {
            if (vertex[w] == 0 && dis[w] < min) {
                min = dis[w];
                u = w;
            }
        }
		// let u as 1, check its neighbor.
        vertex[u] = 1;
		// iteratively calulate their distance.
        for (int v = 0; v < vertex_Num; v++) {
			// for all vertex v that as u's neighbor.
            if (weight_edge[u][v] < 99999) {
				// decrease key for current vertex.
				// if there exists dis that < min, update.
                if (dis[v] > dis[u] + weight_edge[u][v]) {
                    // update min distance.
					dis[v] = dis[u] + weight_edge[u][v];
					// set its parents as u.
					// used to find path that generates min distance.
					pred[v] = u;
                }
            }
        }
    }
	// out put edges for all vertex.
    for (int i = 1; i < vertex_Num; i++) {
        printf("%d--%d ", pred[i], i);
    }
	return;
}


// main function.
int main(){

	// infinite loop for input, until input CTRL+Z.
	while(1){
		// initialize some variables to store filename and rows.
		char filename[30] = "";
		char row[30] = {""};
		// hint for input.
		printf("***************\n");
		printf("Input the file name:\n");
		// scan filename from keyboard, store in filename.
		scanf("%s", filename);
		printf("***************\n");
		// use fp to open the file.
		FILE *fp = NULL;
		fp = fopen(filename,"r");
		// check whether file is available.
		if(fp == NULL){
			// which means filename does not exist.
			printf("WARN! The file does not exist!\n");
			// seek for next input.
			continue;
		}
		// otherwise, file is available to read, continue.
		// used to store the number of vertex.
		fscanf(fp, "%d/n", &vertex_Num);
		// used to store the number of edge.
		fscanf(fp, "%d/n", &edge_Num);
		edge_Num_d = edge_Num * 2;

		// initialize parameters of each vertex.
		for (int i = 0; i < vertex_Num; i++){
			// initialize all nodes' color to be 'w'.
			// and set their pred to be -1.
            color[i] = 'w';
			pred[i] = -1;
			// initialize information between each two vertexes.
            for (int j = 0; j < vertex_Num; j++) {
                if (i == j){
					// which means two vertex are identical.
                    weight_edge[i][j] = 0;
				} else {
					// otherwise, set weight as infinite.
                    weight_edge[i][j] = 99999;
				}
            }
        }

		int p = 0;
        for(int i = 0; i < edge_Num; i++) {
			// as a counter when read in file.
			int counter = 0;
			// int a[3] = {0};
			int p1, p2;
			int w = 0;
			// read in the vertex and their weight.
			fscanf(fp,"%d,%d,%d", &p1, &p2, &w);
			graph[i][0] = p1;
			graph[i][1] = p2;
			graph[i][2] = w;
			// extend graph by exchange u and v.
			// because this is an undirected graph.
			graph[i+edge_Num_d/2][0] = graph[i][1];
			graph[i+edge_Num_d/2][1] = graph[i][0];
			graph[i+edge_Num_d/2][2] = graph[i][2];
			
			// assign the weight of input to matrix.
            weight_edge[p1][p2] = w;
            weight_edge[p2][p1] = w;
            // set edge array according to input.
            e[p].u = p1;
            e[p].v = p2;
			e[p].w = w;
            p++;
        }

		// call corresponding functions.
		// hint for functions' outputs.
		printf("1. The articulation point(s) found in the given graph is/are:\n");
		ReArtPt(0);

		// reset index.
		for (int i = 0; i < vertex_Num; i++){
			// initialize all nodes' color to be 'w'.
			// and set their pred to be -1.
            color[i] = 'w';
			pred[i] = -1;
        }

		printf("The biconnected component(s) found in the given graph is/are:\n");
		// call function to return components.
		ReArtPt_BC(0);
		// for rest components, pop them here.
		for( ; ls > 0; ls--){
			// first, push them into Bicomp stack from S stack.
			Bicomp[lb][0] = S[ls-1][0];
			Bicomp[lb][1] = S[ls-1][1];
			// increase size of Bicomp stack.
			lb++;
		}
		// then pop out all edges from Bicomp.
		if(lb > 0){
			for(int k = 0; k < lb; k++){
				printf("%d--%d ",Bicomp[k][0],Bicomp[k][1]);
			}
			lb = 0;
		}
		printf("\n");
		printf("***************\n");

		// Then excuate MST to find edges in MST.
		printf("2. The following are the edges in the constructed MST:\n");
		MST();
		printf("\n");
		printf("***************\n");

		//Finally find SPT of input file.
		printf("3. The following are the edges in the constructed SPT:\n");
		SPT(vertex_Num);
		printf("\n");

		// close the file.
		fclose(fp);
	}

	return 0;
}


