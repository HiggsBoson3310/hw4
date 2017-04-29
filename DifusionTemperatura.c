#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int position(int x, int y, int n);
void fixed_bound(FILE *f, FILE *g, int c);
void period_bound(FILE *f, FILE *g, int c);
void open_bound(FILE *f, FILE *g, int c);
int main(){
	FILE *f,*g,*f1,*g1,*f2,*g2,*f3,*g3,*f4,*g4,*f5,*g5;
	f = fopen("surface_no_forcing.txt","w");
        g = fopen("Averages_no_forcing.dat","w");
        f1 = fopen("surface_forcing.txt","w");
        g1 = fopen("Averages_forcing.dat","w");
        f2 = fopen("surface_no_forcing_periodic.txt","w");
        g2 = fopen("Averages_no_forcing_periodic.dat","w");
        f3 = fopen("surface_forcing_periodic.txt","w");
        g3 = fopen("Averages_forcing_periodic.dat","w");
        f4 = fopen("surface_no_forcing_open.txt","w");
        g4 = fopen("Averages_no_forcing_open.dat","w");
        f5 = fopen("surface_forcing_open.txt","w");
        g5 = fopen("Averages_forcing_open.dat","w");
        fixed_bound(f,g,0);
        fixed_bound(f1,g1,1);
        period_bound(f2,g2,0);
        period_bound(f3,g3,1);
        open_bound(f4,g4,0);
        open_bound(f5,g5,1);
	return 0;
}
int position(int x, int y, int n){
	int z;
	z = x+(n*y);
	return z;
}

void fixed_bound(FILE *f, FILE *g, int c){
        int y=0,x=0,n=0;
	float dt, ds=0.01,a,v=0.0001,t=0,chi,m=0.0;
	dt = (0.2*ds*ds)/v;
	a = dt/(ds*ds);
	chi = a*v;
	printf("Este es alpha*nu: %f y este es dt %f\n",chi,dt);
	int tn=2500/dt, sn=1/ds;
	printf("Van a darse %d iteraciones en el tiempo y el cuadrado tendra %d columnas\n",tn,sn);
	float *surface=malloc(sn*sn*sizeof(float));
	printf("Inicializando Matriz \n");
	for(y=0;y<sn;y++){
	  for(x=0;x<sn;x++){
	    if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
	    else{surface[position(x,y,sn)]=50.0;}
	    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
	    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
            m+=surface[position(x,y,sn)]/(sn*sn);
	  }
	}
	fprintf(g,"%f %f\n",t,m); 
	printf("Matriz incializada y guardada\n");
	printf("Comenzando proceso de iteracion \n");
	for(n=1;n<=tn;n++){
          m=0;  
	  t=n*dt;
	  float *past=malloc(sn*sn*sizeof(float));
	  for(x=0;x<sn;x++){
	    for(y=0;y<sn;y++){
	      past[position(x,y,sn)]=surface[position(x,y,sn)];
	    }
	  }
	  for(x=1;x<(sn-1);x++){
	    for(y=1;y<(sn-1);y++){
              if(c==1){
                if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
                else{surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];}  
              }
              else{
                surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
              }
                m+=surface[position(x,y,sn)]/(sn*sn);
	    }
          }
          fprintf(g,"%f %f\n",t,m); 
          free(past);
          
	  if (t==100){
              fprintf(f,"t=100\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          if (t==2500){
              fprintf(f,"t=2500\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          
	}
	fprintf(f,"ENDENDENDENDEND");
        printf("Proceso de iteracion terminado, matrices generadas y guardadas");
}
void period_bound(FILE *f, FILE *g, int c){
        int y=0,x=0,n=0;
	float dt, ds=0.01,a,v=0.0001,t=0,chi,m=0.0;
	dt = (0.2*ds*ds)/v;
	a = dt/(ds*ds);
	chi = a*v;
	printf("Este es alpha*nu: %f y este es dt %f\n",chi,dt);
	int tn=2500/dt, sn=1/ds;
	printf("Van a darse %d iteraciones en el tiempo y el cuadrado tendra %d columnas\n",tn,sn);
	float *surface=malloc(sn*sn*sizeof(float));
	printf("Inicializando Matriz \n");
	for(y=0;y<sn;y++){
	  for(x=0;x<sn;x++){
	    if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
	    else{surface[position(x,y,sn)]=50.0;}
	    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
	    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
            m+=surface[position(x,y,sn)]/(sn*sn);
	  }
	}
	fprintf(g,"%f %f\n",t,m); 
	printf("Matriz incializada y guardada\n");
	printf("Comenzando proceso de iteracion \n");
	for(n=1;n<=tn;n++){
          m=0;  
	  t=n*dt;
	  float *past=malloc(sn*sn*sizeof(float));
	  for(x=0;x<sn;x++){
	    for(y=0;y<sn;y++){
	      past[position(x,y,sn)]=surface[position(x,y,sn)];
	    }
	  }
	  for(x=0;x<(sn-1);x++){
	    for(y=0;y<(sn-1);y++){
              if(c==1){
                if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
                else if(x==0){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                    else if(y==sn-1){
                        surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                }
                else if(x==(sn-1)){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    if(y==(sn-1)){
                        surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                }
                else if(y==0 && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else if(y==(sn-1) && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else{surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];}  
              }
              else{
                if(x==0){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                    else if(y==sn-1){
                        surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(sn-1,y,sn)];
                    }
                }
                else if(x==(sn-1)){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else if(y==(sn-1)){
                        surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(0,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                }
                else if(y==0 && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,sn-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else if(y==(sn-1) && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,0,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else{surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];}
              }
                m+=surface[position(x,y,sn)]/(sn*sn);
	    }
          }
          fprintf(g,"%f %f\n",t,m); 
          free(past);
          
	  if (t==100){
              fprintf(f,"t=100\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          if (t==2500){
              fprintf(f,"t=2500\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          
	}
	fprintf(f,"ENDENDENDENDEND");
        printf("Proceso de iteracion terminado, matrices generadas y guardadas");
}
void open_bound(FILE *f, FILE *g, int c){
        int y=0,x=0,n=0;
	float dt, ds=0.01,a,v=0.0001,t=0,chi,m=0.0;
	dt = (0.2*ds*ds)/v;
	a = dt/(ds*ds);
	chi = a*v;
	printf("Este es alpha*nu: %f y este es dt %f\n",chi,dt);
	int tn=2500/dt, sn=1/ds;
	printf("Van a darse %d iteraciones en el tiempo y el cuadrado tendra %d columnas\n",tn,sn);
	float *surface=malloc(sn*sn*sizeof(float));
	printf("Inicializando Matriz \n");
	for(y=0;y<sn;y++){
	  for(x=0;x<sn;x++){
	    if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
	    else{surface[position(x,y,sn)]=50.0;}
	    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
	    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
            m+=surface[position(x,y,sn)]/(sn*sn);
	  }
	}
	fprintf(g,"%f %f\n",t,m); 
	printf("Matriz incializada y guardada\n");
	printf("Comenzando proceso de iteracion \n");
	for(n=1;n<=tn;n++){
          m=0;  
	  t=n*dt;
	  float *past=malloc(sn*sn*sizeof(float));
	  for(x=0;x<sn;x++){
	    for(y=0;y<sn;y++){
	      past[position(x,y,sn)]=surface[position(x,y,sn)];
	    }
	  }
	  for(x=0;x<(sn-1);x++){
	    for(y=0;y<(sn-1);y++){
              if(c==1){
                if(19<x && x<41 && 44<y && y<56){surface[position(x,y,sn)]=100.0;}
                else if(x==0){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                    else if(y==sn-1){
                        surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                }
                else if(x==(sn-1)){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    if(y==(sn-1)){
                        surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                }
                else if(y==0 && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else if(y==(sn-1) && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else{surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];}  
              }
              else{
                if(x==0){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                    else if(y==sn-1){
                        surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x,y,sn)];
                    }
                }
                else if(x==(sn-1)){
                    if(y==0){
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else if(y==(sn-1)){
                        surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                    else{
                        surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x-1,y,sn)];
                    }
                }
                else if(y==0 && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else if(y==(sn-1) && x!=0 && x!=(sn-1)){
                    surface[position(x,y,sn)] = chi*past[position(x,y,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];
                }
                else{surface[position(x,y,sn)] = chi*past[position(x,y+1,sn)]+(1-4*chi)*past[position(x,y,sn)]+chi*past[position(x,y-1,sn)]+chi*past[position(x+1,y,sn)]+chi*past[position(x-1,y,sn)];}
              }
                m+=surface[position(x,y,sn)]/(sn*sn);
	    }
          }
          fprintf(g,"%f %f\n",t,m); 
          free(past);
          
	  if (t==100){
              fprintf(f,"t=100\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          if (t==2500){
              fprintf(f,"t=2500\n");
              for(y=0;y<sn;y++){
                for(x=0;x<sn;x++){
                    if(x==(sn-1)){fprintf(f,"%f\n",surface[position(x,y,sn)]);}
                    else{fprintf(f,"%f ",surface[position(x,y,sn)]);}
                }
              }
          }
          
	}
	fprintf(f,"ENDENDENDENDEND");
        printf("Proceso de iteracion terminado, matrices generadas y guardadas");
}