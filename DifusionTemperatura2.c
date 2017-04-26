#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int position(int x, int y, int n);
int main(){
	FILE *f;
	f = fopen("surface.txt","w");
	int y=0,x=0,n=0;
	float dt, ds=0.01,a,v=0.0001,t=0,chi;
	dt = (0.2*ds*ds)/v;
	a = dt/(ds*ds);
	chi = a*v;
	printf("Este es alpha*nu: %f y este es dt %f\n",chi,dt);
	int tn=2500/dt, sn=1/ds;
	printf("Van a darse %d iteraciones en el tiempo y el cuadrado tendra %d columnas\n",tn,sn);
	float *surface=malloc(sn*sn*sizeof(float));
	printf("Inicializando Matriz \n");
	fprintf(f,"t=0\n");
	for(y=0;y<sn;y++){
	  for(x=0;x<sn;x++){
	    if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
	    else{surface[position(x,y,sn)]=50.0;}
	    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
	    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
	  }
	}
	printf("Matriz incializada, guardada en surafce.txt \n");
	printf("Comenzando proceso de iteracion \n");
	printf("t= %f, Temperatura para x=19, y=20: %f \n",t,surface[position(20,19,sn)]);
	for(n=1;n<tn;n++){
	  t=n*dt;
	  float *past=malloc(sn*sn*sizeof(float));
	  for(x=0;x<sn;x++){
	    for(y=0;y<sn;y++){
	      past[position(x,y,sn)]=surface[position(x,y,sn)];
	    }
	  }
	  for(x=1;x<(sn-1);x++){
	    for(y=1;y<(sn-1);y++){
	      surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
	    }
	  }
	  printf("t= %f, Temperatura para x=19, y=20: %f \n",t,surface[position(20,19,sn)]);
          free(past);
	}
	return 0;
}
int position(int x, int y, int n){
	int z;
	z = x+(n*y);
	return z;
}
