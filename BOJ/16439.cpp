#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int* chicken;
bool* select_c;
int max = 0;
int** like;
int n_member; 
int m_chicken;


void DFS(int index, int cnt);
void multiple();
void initialize_chicken();

int main(){
	
	scanf("%d %d",&n_member, &m_chicken);	
	chicken = (int*)malloc(sizeof(int)*m_chicken);
	select_c = (bool*)malloc(sizeof(bool)*m_chicken);
	like = (int**)malloc(sizeof(int*)*n_member);
	for(int i=0; i<n_member; i++){
		like[i] = (int*)malloc(sizeof(int)*m_chicken);
	}

	for(int i =0; i<n_member;i++){
		for(int j=0; j<m_chicken; j++){
			scanf("%d",&like[i][j]);
		}
	}

	DFS(0,0);

	free(chicken);
	free(select_c);
	printf("%d",max);
	return 0;
}

void DFS(int index, int cnt){
	if(cnt == 3){
		multiple();
		return;
	}
	for(int i=index; i<m_chicken; i++){
		if(select_c[i] ==true) continue;
		select_c[i] = true;
		DFS(i,cnt+1);
		select_c[i] = false;
	}
}
void multiple(){
	int sum = 0;
	int max_c =0;
	initialize_chicken();
	for(int i=0; i<n_member; i++){
		for(int j=0; j<m_chicken; j++){
			if(max_c < like[i][j]*chicken[j])
			       max_c = like[i][j]*chicken[j];	
		
		}
		sum += max_c;	
		max_c = 0;	
	}
	if(sum >max){
	max = sum;
	}

}
void initialize_chicken(){
	for(int i=0; i<m_chicken; i++){
		chicken[i] = 0;
		if(select_c[i] == true)
			chicken[i] =1;
	}

}
