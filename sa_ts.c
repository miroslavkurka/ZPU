#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 100
#define T_INIT 1e8


double x[COUNT];
double y[COUNT];
int coor_index[COUNT];
double distance[COUNT][COUNT];

void rand_gen(double x[], double y[]) {
    for (int i=0; i<COUNT;++i){
        coor_index[i]=i;
        x[i]= 100.0*rand()/RAND_MAX;
        y[i]= 100.0*rand()/RAND_MAX;}
    

}

void euclidian_length(double field[COUNT][COUNT]){
    for (int j=0; j<COUNT;++j)
        for  (int k=0; k<COUNT; ++k)
            field[j][k]= sqrt(pow(x[j]-x[k],2)+pow(y[j]+y[k],2));
	
}

double print_dist(int flag){
    double dist=0.0;
    
    for (int i=0; i<COUNT; ++i){
        dist+=distance[coor_index[i]][coor_index[(i+1)%COUNT]];
	for (int j=0; j<COUNT; ++j)
            if (flag){
                printf("step (i,j): %d, %d  matrix: %g\n",i,j,distance[i][j]);}

}
    if (flag){ 
        printf("Distance is  %g\n",dist);}
    return dist;
    

}
void change_places(int i, int j){
    int tmp= coor_index[i];
    coor_index[i]=coor_index[j];
    coor_index[j]= tmp;
}
double anneal(int cycles){
    double temp, delta_e;
    double real_distance= print_dist(0); 

    int i=0;
    while(++i<cycles){
        temp=T_INIT/i;

        double random_place1=rand()%COUNT;
        double random_place2=rand()%COUNT;
        if (random_place1==random_place2){
            continue;
        }
        else{
            change_places(random_place1,random_place2);
            double possible_distance=print_dist(0);
            delta_e= possible_distance - real_distance;
          
            if (rand()/RAND_MAX > exp(-delta_e/temp)){
                change_places(random_place2,random_place1);
            }
            else{
                real_distance=possible_distance;
            }
        }
     }
    return real_distance;
}

int main(){

    printf("Cycles of annealing: ");
    int c=getchar();
    rand_gen(x,y);
    euclidian_length(distance);
    //print_dist();
    printf("Optimal path should be: %g\n",anneal(c));

}
