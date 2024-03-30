#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

struct Particle{
    //Posiciones de la particula
    double x = 0;
    double y = 0;
    //Particula valida dentro de la simulacion
    bool valid = true;

    void move(){
        int direction = rand() % 4;
        switch(direction){
            //Abajo
            case 0:
                if (y >= 0){
                    y -= 1;
                }else{
                    valid = false;
                }
                break;

            //Arriba
            case 1:
                if (y <= 100){
                    y += 1;
                }else{
                    valid = false;
                }
                break;

            //Izquierda
            case 2:
                if (x >= 0){
                    x -= 1;
                }else{
                    valid = false;
                }
                break;

            //Derecha
            case 3:
                if (x <= 100){
                    x += 1;
                }else{
                    valid = false;
                }
                break;
        }
    }

};

typedef std::vector<Particle> particles;

void init(particles & position, int seed);
void update(particles & position, int nsteps);

int main(){
    int Nmol = 400;
    int LatSize = 64;
    int Nsteps = 100000;
    int SEED = 0;

    particles prueba1;
    prueba1.resize(Nmol);

    //Semilla aleatoria 
    srand(time(NULL));
    init(prueba1, SEED);
    //update(prueba1, Nsteps);

    return 0;
}

//Incializar posiciones
void init(particles & position, int seed){
    int N = position.size();
    
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> distribution(0.1, 0.9);

    for(int jj = 0; jj < N; jj++){
        position[jj].x = 45 + 10*distribution(generator);
        position[jj].y = 45 + 10*distribution(generator);

    }
}

//actualizar posiciones
void update(particles & position, int nsteps){
    int N = position.size();

    std::ofstream outfile;
    outfile.open("positions.txt");
    for(int ii = 0; ii < nsteps; ii++){
        outfile << ii << "\t";
        for(int jj = 0; jj < N; jj++){
            //Verificar una posicion valida
            if(position[jj].valid){
                position[jj].move();
            }
        outfile << position[jj].x << "\t" << position[jj].y << "\t";
        }
        outfile << "\n";
    }
    outfile.close();
}

