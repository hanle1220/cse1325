#include "mandelbrot.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    int width = 1000, height = 1000, icount = 60, nthreads = 1;   
    std::string filename = "image.ppm";

    try{
        for(int i=1; i<argc-1; i++){
            if(atoi(argv[i]) == 0 ) throw std::invalid_argument{"Invalid argument"};
            else {
                if(argc >= 2) width = std::stoi(argv[1]);   
                if(argc >= 3) height = std::stoi(argv[2]);  
                if(argc >= 4) icount = std::stoi(argv[3]); 
                if(argc <= 6) nthreads = std::stoi(argv[4]);   
            }    
        }
         std::cout << "  width: " << width << "  height: " << height << "  icount: " << icount << "  threads: " << nthreads << std::endl;        
    }    catch(std::invalid_argument e){
            std::cerr << e.what() << std::endl;
            return -2;
        }

    try{
        if(argc == 6) filename = argv[5];
        std::ofstream ofs{filename};
        if(!ofs) throw std::runtime_error{"Error writing file"};        
        ofs << Mandelbrot {width, height, icount, nthreads};
        std::cout << "  wrote: " << filename << std::endl;
        
    }   catch(std::exception& e){
            std::cerr << e.what() << std::endl;
            return -1;
        }
}
