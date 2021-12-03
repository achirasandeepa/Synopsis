#include <iostream>
using namespace std;

class CoffeeMachineInterface {
    public:
        CoffeeMachineInterface(){
            cout << "Coffee machine interface" << endl;
        }

        virtual void chooseFirstSelection(){
            cout << "Select flavor 1 of NEW coffee machine" << endl;
        }

        virtual void chooseSecondSelection(){
            cout << "Select flavor 2 of NEW coffee machine" << endl;
        }
};

class OldCoffeeMachine {
    public:
        OldCoffeeMachine(){
            cout << "Activate old machine" << endl;
        }
        
        void selectA(){
            cout << "Select flavor 1" << endl;
        }

        void selectB(){
            cout << "Select flavor 2" << endl;
        }
};

class CoffeeTouchscreenAdapter : public CoffeeMachineInterface {
    public:

        OldCoffeeMachine* OldVendingMachine;

        CoffeeTouchscreenAdapter(OldCoffeeMachine* machine): 
                        OldVendingMachine{machine}
        {
            cout << "Connect touch screen adapter" << endl;
        }

        void chooseFirstSelection(){
            OldVendingMachine->selectA();
        }

        void chooseSecondSelection(){
            OldVendingMachine->selectB();
        }
};

int main(){

    //New machine
    CoffeeMachineInterface* CoffeeMachine;

    CoffeeMachine = new CoffeeMachineInterface;
    CoffeeMachine->chooseFirstSelection();
    CoffeeMachine->chooseSecondSelection();
    cout << endl;
    delete CoffeeMachine;

    // Old machine
    OldCoffeeMachine OldMachine;
    CoffeeMachine = new CoffeeTouchscreenAdapter{&OldMachine};
    CoffeeMachine->chooseFirstSelection();
    CoffeeMachine->chooseSecondSelection();
    cout << endl;
    delete CoffeeMachine;
    CoffeeMachine = nullptr;

    return 0;
}
