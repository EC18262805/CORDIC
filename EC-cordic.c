//Eoghan Campion 18262805//
//Cordic Prosessor		//
#include <stdio.h>
#include <math.h>

int main()
{
int theta = 60;
int steps = 6;
int i;
double C, S, C_old, S_old, A, rad;
const double PI = 3.1415926535;

printf("i   DelA       C_old      C          S_old      S             A\n");
double DelA = 45 ;
	
A = 45; C = 0.607352;

if (theta >= 0){
	S = 0.607352;		
}
else{
	S = -0.607352;
}
	
	for (i = 0; i < steps; i += 1 ) {
			
		DelA = DelA/2 ;
		rad = DelA * (PI/180);
			
		C_old = C; S_old = S;
		if (A <= theta ) { 			/*undershoot*/
			A += DelA;
			C = 1*(C) - (2^-(steps-1))*(S);
			S = (2^-(steps-1))*(C)+1*(S); 
			printf("%d   %f   %f   %f   %f   %f    %f    Under \n", i, DelA, C_old, C, S_old, S, A);
		}
		
		else {						/*overshoot*/
			A -= DelA;
			C = 1*(C) + (2^-(steps-1))*(S);
			S = -(2^-(steps-1))*(C)+1*(S);
			printf("%d   %f   %f   %f   %f   %f    %f    Over  \n", i, DelA, C_old, C, S_old, S, A);
		}
		

	}
	
	double Cres = acos(C)*(180/PI);
	printf("\nC = %f \nS = %f",C ,S);	
	printf("\n%d step search for %d result = %f degrees\n",steps, theta, Cres);
	
}
