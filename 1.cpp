#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	float N,K;
}Input;

Input * ReadFromFile(float *n){
	FILE *f;
	f=fopen("TOHOP.inp","r");
	Input *dss;
	dss=(Input*)malloc(sizeof(Input));
	int i=0;
	while(!feof(f)){
		fscanf(f,"%f%f",&dss[i].N,&dss[i].K);
		i++;
		dss=(Input*)realloc(dss, sizeof(Input)*(i+1));
	}
	*n=i;
	fclose(f);
	return dss;
}

int Tohop(int n,int k){
	if( k == 0 || k == n)
		return 1;
	return (Tohop( n-1 , k-1 ) + Tohop( n-1 , k ));
}

int Ketqua(Input *dss , int n){
	int i,A;
	FILE *f;
	f=fopen("TOHOP.out","wt");
	for(i=0;i<n;i++){
		A=Tohop(dss[i].N,dss[i].K);
		printf("%d\n",A);
		fprintf(f,"%d\n",A);
	}
}

int main(){
	float n;	
	Input *dss;
	dss=ReadFromFile(&n);
	Ketqua(dss,n);
	return 0;
	
}
