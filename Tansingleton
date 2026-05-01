#include <iostream>      
using namespace std; 

class Tansingleton
{
    private:
        static Tansingleton* uniqurevariable; 
        Tansingleton(){}

    public:
        static Tansingleton* getIntance(){     
            if (uniqurevariable == nullptr)
            {
                uniqurevariable = new Tansingleton();
            }
            return uniqurevariable;
        }
        void sayHi(){
            cout << "hello world";
        }
};

Tansingleton* Tansingleton::uniqurevariable = nullptr;

int main(){
    Tansingleton::getIntance()->sayHi();
    return 0;
}