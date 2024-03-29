#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

struct Particle{
    double x = 50;
    double y = 50;

    //Constructor
    //Particle(double xint, double yint){
       //this -> x = xint;
        //this -> y = yint;
    //}

    void move(double xmax, double ymax){
        int direction = rand() % 4;
        switch(direction){
            //Abajo
            case 0:
                if (y > 0){
                    y -= 1;
                }else{
                    y += 1;
                }
                break;

            //Arriba
            case 1:
                if (y < ymax){
                    y += 1;
                }else{
                    y -= 1;
                }
                break;

            //Izquierda
            case 2:
                if (x > 0){
                    x -= 1;
                }else{
                    x += 1;
                }
                break;

            //Derecha
            case 3:
                if (x < xmax){
                    x += 1;
                }else{
                    x -= 1;
                }
                break;
        }
    }

};

typedef std::vector<Particle> particles;

//void init(particles & position);
void update(particles & position, int nsteps);

int main(){
    int Nmol = 500;
    int LatSize = 64;
    int Nsteps = 1000;
    int seed = 0;

    particles prueba1;
    prueba1.resize(Nmol);

    //Semilla aleatoria 
    srand(time(NULL));
    update(prueba1, Nsteps);

    return 0;
}

//actualizar posiciones
void update(particles & position, int nsteps){
    int N = position.size();

    std::ofstream outfile;
    outfile.open("positions.txt");
    for(int ii = 0; ii < nsteps; ii++){
        outfile << ii << "\t";
        for(int jj = 0; jj < N; jj++){
            position[jj].move(100, 100);
            outfile << position[jj].x << "\t" << position[jj].y << "\t";
        }
        outfile << "\n";
    }
    outfile.close();
}
