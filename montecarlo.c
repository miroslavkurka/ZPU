include<stdio.h>
include<math.h>

/* Monte Carlo integration of circle 
 *
 *
 * TODO: random sampling in main
 */
bool in_circle(float x, float y) {

        if (pow(x,2.0) + pow(y,2.0) < pow(radius, 2.0)
			return true;  


	return false;
}

double monte_carlo( int n){

	pi_count = 0;

	for (int i=0; i < n; i++){
		double x = rand();
		double y = rand();
		if (in_circle(x,y)a)
			pi_count+=1	
	} 




}
int main(void) {






}
