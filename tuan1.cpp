#include<stdio.h>
#define max 20

struct GRAPH {
	int arr[max][max];
	int n;
};

void readMatrixFromFile(GRAPH &g, char filename[30]) {
	FILE *f;
	f = fopen(filename, "rt");
	if(f == NULL)
		printf("Error");
	else {
		fscanf(f, "%d", &g.n);
		for(int i = 0; i < g.n; i++) {
			for(int j = 0; j < g.n; j++) {
				fscanf(f, "%d", &g.arr[i][j]);
			}
		}
		fclose(f);
	}
}

void outputMatrix(GRAPH g) {
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++) {
			printf("%d ", g.arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool checkKhuyen(GRAPH g) {
	for(int i = 0; i < g.n; i++) {
		if(g.arr[i][i] != 0) {
			return true; //co khuyen 
		}
	}
	return false;
}

bool checkCoHuong(GRAPH g) {
	for(int i =  0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++) {
			if(g.arr[i][j] != g.arr[j][i])
				return true; //co huong
		}
	}
	return false; 
}

int main() {
	GRAPH graph;
	char filename[60] = "C:\\Users\\Administrator\\Desktop\\asd.txt";
	
	readMatrixFromFile(graph, filename);
	
	outputMatrix(graph);
	
	if(checkKhuyen(graph) == true) 
		printf("Co Khuyen\n");
	else
		printf("Khong Khuyen\n");
		
	if(checkCoHuong(graph) == true)
		printf("Co Huong\n");
	else
		printf("Khong Co Huong\n");
}




