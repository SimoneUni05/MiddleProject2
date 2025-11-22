#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/MyVector.h"
#include <cstdlib>   
#include <ctime> 
int main() {
    srand (time(NULL));
    InertialDriver driver=InertialDriver();
    for (int i=0;i<20;i++){ // genera 20 misure e le inserisce nel buffer
        Misura m=Misura();
        for (j=0;j<17;j++){
            /*generazione casuale dei valori di Lettura in un range circa verosimile per semplictà 
            velocità angolare: -3 a 18 radianti al secondo
            accelerazione angolare: -18 a 87 radianti al secondo quadrato
            Sono stati scelti raggrupamenti di valori per semplcita
            */
            double yaw_v {(rand()%210000)/10000.0 -3};
            double pitch_v {(rand()%210000)/10000.0 -3};
            double roll_v {(rand()%210000)/10000.0 -3};

            double yaw_a {(rand()%1050000)/10000.0 -18};
            double pitch_a {(rand()%1050000)/10000.0 -18};
            double roll_a {(rand()%1050000)/10000.0 -18};
            m[j] = Lettura {yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a}; // [Test per l'inserimento]
        }
        if (i=0)
            std::cout << "prima misura inserita nel buffer:\n" << m << '\n'; //dovrebbe essere sovrascritto
        if (i==10)
            std::cout << "undicesima misura inserita nel buffer (e quella che dovrebbe uscire alla chiamata di pop_front) e':\n" << m << '\n';
        if (i==19)   
            std::cout << "ultima misura inserita nel buffer:\n" << m << '\n';
        driver.push_back(m);
    }
    sdt::cout << "[TEST:get_reading()] Nell'ultima misura inserita il valore dell'ultimo sensore è :" << driver.get_reading(16) << '\n';

    std::cout << "[TEST:pop_front()] La misura piu' vecchia nell buffer e': " << driver.pop_front() << '\n';
}

