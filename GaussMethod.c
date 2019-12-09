#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int i, j, n, ii;
double A[500][500];

void gaus()
{
	int j2,s = 0;
	double k, det = 1, t = 0;

	for(i = 0; i < n-1; i++)
	{
		if (A[i][i] != 0)
			for(ii = i+1; ii < n; ii++)
			{
				k = -A[ii][i] / A[i][i];
				for(j = 0; j < n+1; j++) A[ii][j] = A[ii][j]+(A[i][j]*k);
			}

		else
			for(ii = i+1; ii < n; ii++){
				for(j = 0; j < n+1; j++)
					if(j == i && A[ii][j] != 0){
						s++;
						for (j = 0;j <= n; j++){
							t = A[i][j];
							A[i][j] = A[ii][j];
							A[ii][j] = t;
      					}
					}
   			}
	}
	printf ("\nNew Matrix\n");
	for(i = 0; i < n; i++) {
	   for(j = 0; j < n; j++) printf ("%5.2f \t", A[i][j]);
		printf ("\n");
	}

	for (i = 0; i < n; i++) det = det * A[i][i];
	if(s % 2 != 0) det = det * (-1);
	if(fabs(det) < 1E-12) det = 0;
	printf("\nDeterminant= %.2lf\n", det);
}



int main (){
	printf("Enter n = ");
	scanf("%d", &n);
	printf("Enter matrix:\n");
	for(i = 0; i < n; i++)
    	for(j = 0; j < n; j++)
			scanf("%lf", &A[i][j]);
	printf ("\n");
	gaus();
}