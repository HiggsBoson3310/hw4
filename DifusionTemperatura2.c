#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	FILE *f;
	f = fopen("surface.txt","w");
	int y=0,x=0,n=0;
	float dt, ds=0.01,a,v=0.3,t=0,chi;
	dt = (0.2*ds*ds)/v;
	a = dt/(ds*ds);
	chi = a*v;
	printf("Este es alpha*nu: %f y este es dt %f\n",chi,dt);
	int tn=100, sn=1/ds;
	printf("Van a darse %d iteraciones en el tiempo y el cuadrado tendra %d columnas\n",tn,sn);
	float *surface=malloc(sn*sn*sizeof(float));
	printf("Inicializando Matriz \n");
	fprintf(f,"t=0\n");
	for(y=0;y<sn;y++){
	  for(x=0;x<sn;x++){
	    if(19<x && x<41 && 44<y && y<56){surface[position(x,y)]=100.0;}
	    else{surface[y][x]=50.0;}
	    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y)]);}
	    else{fprintf(f,"%f ",surface[position(x,y)]);}
	  }
	}
	printf("Matriz incializada, guardada en surafce.txt \n");
	printf("Comenzando proceso de iteracion \n");
	printf("t= %f, Temperatura para x=19, y=20: %f \n",t,surface[position(20,19)]);
	for(n=1;n<tn;n++){
	  t=n*dt;
	  float past[sn][sn];
	  for(x=0;x<sn;x++){
	    for(y=0;y<sn;y++){
	      past[y][x]=surface[y][x];
	    }
	  }
	  for(x=1;x<(sn-1);x++){
	    for(y=1;y<(sn-1);y++){
	      surface[y][x] = chi*past[y+1][x]+(1-2*chi)*past[y][x]+chi*past[y-1][x]+chi*past[y][x+1]+(1-2*chi)*past[y][x]+chi*past[y][x-1];
	    }
	  }
	  printf("t= %f, Temperatura para x=19, y=20: %f \n",t,surface[20][19]);
	}
	return 0;
}
int position(int x, int y, int n){
	int z;
	z = x+(n*y);
	return z;
}
