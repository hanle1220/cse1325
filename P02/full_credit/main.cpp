#include <ctime>
#include <iostream>

int main(){
    srand(time(NULL));
        
    int dice, face, roll, num;

    std::cout << "Number of dice? " ;
    std::cin >> dice;
    
    std::cout << "Number of faces per dice? ";
    std::cin >> face;

    std::cout << "Number of rolls? " ; 
    std::cin >> roll;

    for(int i=0; i<roll; i++){
         int sum = 0; 
         
         std::cout << "Roll " << i << ": ";

         for(int j=0; j<dice; j++){
            num = rand()%face+1; 
            std::cout << num << " ";
            sum += num;
          } std::cout << "Sum: "<< sum << std::endl;

    }

} 

