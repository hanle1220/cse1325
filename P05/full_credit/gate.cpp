#include<iostream>
#include<vector>

class Gate{
    
    public:  
        typedef int Pin;
        typedef int Signal;    
        Gate(){
            _input1 = 0;
            _input2 = 0;
            _to_pin = 0;
        }

        void connect(Gate& gate, Pin input_pin){
            *to_gate = gate;
            _to_pin = input_pin;
            input(_to_pin, gate.output());
        }

        Signal input(Pin pin){ 
            if(pin==1) return _input1; 
            else return _input2; 
        }

        void input(Pin pin, Signal signal){
            if(pin==1) _input1 = signal;
            if(pin==2) _input2 = signal;           
       }

        virtual Signal output() = 0 ;
    private:
        Signal _input1;
        Signal _input2; 
        Gate* to_gate;
        Pin _to_pin;
};
     
class And: public Gate {
    public: 
        virtual Signal output() override { return input(1) & input(2);}
};

class Or: public Gate {
     public: 
        virtual Signal output() override { return input(1) || input(2);}       
};

int main(){
    std::vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> B = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    std::vector<int> C = {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    std::vector<int> D = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

    And a1, a2;
    Or o;
    std::cout<< "A B C D  Q\n= = = =  =\n";
    for(int i = 0; i<A.size(); i++){
        a1.input(1, A[i]);
        a1.input(2, B[i]); a1.output();
        o.connect(a1, 1 );
        a2.input(1, C[i]);
        a2.input(2, D[i]); a2.output();
        o.connect(a2, 2);
        
        std::cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << "  " << o.output() << "\n";
    }

   
    
}
