#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*float interationCalc(float *past, float *present, float *future)*/

int main(){
	FILE *f1;
	f1 = fopen("surface1.txt","w");
	FILE *f2;
	f2 = fopen("surface2.txt","w");
	FILE *f3;
	f3 = fopen("surface3.txt","w");
	FILE *fg;
	fg = fopen("surface_gif.txt","w");
	int i = 0, j = 0, n = 0;	
	float dt, ds = 0.01, a, v = 0.0001;
        dt = (0.2*ds*ds)/v; 
        a = dt/(ds*ds);
        printf("Este es alpha*v %f y este dt %f\n",a*v,dt);
	int tn = 100, sn = 1/ds;
	float surface1[sn][sn];
	float surface2[sn][sn];
	float surface3[sn][sn];
	fprintf(f1,"t=0\n");
	fprintf(f2,"t=0\n");
	fprintf(f3,"t=0\n");
	fprintf(fg,"t=0\n");
        printf("SUGHSDKDNF K EN FKERVKEFVD \n");
	for (i=0;i<sn;i++){
		for (j=0;j<sn;j++){
			surface3[i][j] = 50.00;			
			if(19<j && j<41 && 44<i && i<56){
				surface1[i][j] = 100.00;
				surface2[i][j] = 100.00;
			}
			else{
				surface1[i][j] = 50.00;
				surface2[i][j] = 50.00;
				
			}
			if(j == (sn-1)){ 
				fprintf(f1,"%f\n",surface1[i][j]);
				fprintf(f2,"%f\n",surface2[i][j]);
				fprintf(f3,"%f\n",surface3[i][j]);
				fprintf(fg,"%f\n",surface1[i][j]);
				
			}
			else {
				fprintf(f1,"%f ",surface1[i][j]);
				fprintf(f2,"%f ",surface2[i][j]);
				fprintf(f3,"%f ",surface3[i][j]);
				fprintf(fg,"%f ",surface1[i][j]);
			}	
		}
	}

	for (n=1; n<tn;n++){
		float t = n*dt;
		float past1[sn][sn];

		for (i=0;i<sn;i++){
			for (j=0;j<sn;j++){
				past1[i][j] = surface1[i][j];
			}
		}


		for (i=1;i<sn-1;i++){
			for (j=1;j<sn-1;j++){
                            
				surface1[i][j] = (v*a)*past1[i+1][j]+(1-2*v*a)*past1[i][j]+(v*a)*past1[i-1][j]+(v*a)*past1[i][j+1]+(1-2*v*a)*past1[i][j];				
			}
		}
		printf("%f\n",surface1[2][2]);
		
        }
}		



