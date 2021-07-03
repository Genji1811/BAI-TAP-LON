#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char n[20];
	float g,v,DG;
	int SL;
}DoVat;

DoVat * ReadFromFile(float *W, int *N){
	FILE *f;
	f=fopen("BAG.inp","r");
	fscanf(f,"%f%f",N,W);
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].g,&dsdv[i].v,&dsdv[i].n);
		
		dsdv[i].DG=dsdv[i].v/dsdv[i].g;
		dsdv[i].SL=0;
		i++;
		dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}
	*N=i;
	fclose(f);
	return dsdv;
}

int swap(DoVat *x, DoVat *y){
		DoVat temp;
		temp = *x;
		*x   = *y;
		*y   = temp;
}

int Sapxep(DoVat *dsdv,int N){
	int i,j;
	for(i=0; i<=N-2;i++)
		for(j=N-1; j>=i+1;j--){
			if(dsdv[j].DG>dsdv[j-1].DG)
				swap(&dsdv[j],&dsdv[j-1]);
		}
}

int Ketqua(DoVat *dsdv , int N , int W){
	int i;
	int TongGT;
	FILE *f;
	f=fopen("BAG.out","wt");
	for(i=0;i<N;i++){
		TongGT+=dsdv[i].SL*dsdv[i].v;
	}
	printf(" %d\n",TongGT);
	fprintf(f," %d\n",TongGT);
	for(i=0;i<N;i++){
		printf("%s %d\n",dsdv[i].n,dsdv[i].SL);
		fprintf(f,"%s %d\n",dsdv[i].n,dsdv[i].SL);
	}
	fclose(f);
}

int Thaman(DoVat *dsdv,int N,float W){
	int i;
	for(i=0;i<N;i++){
		dsdv[i].SL = (W/dsdv[i].g);
		W = W-dsdv[i].SL * dsdv[i].g;
	}
}

int main(){
	int N;
	float W;
	DoVat *dsdv;
	dsdv=ReadFromFile(&W, &N);
	Sapxep(dsdv,N);
	Thaman(dsdv,N,W);
	Ketqua(dsdv,N,W);
	free(dsdv);
	return 0;
}

