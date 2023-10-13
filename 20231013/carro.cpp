#include <iostream>

using namespace std;

class Carro{
    protected:
    int numPortas;

    bool numPortasIsValid(int numPortas){
        bool flag = false;

        flag = (numPortas >= 1 && numPortas <= 7);

        return flag;
    }

    public:
        string tipo;
        string placa;
        string cor;

        Carro(string _placa){
            this->cor = "indefinido";
            this->placa = _placa;
            this->tipo = "indefinido";
            this->numPortas = 2;
        }

        Carro(string _placa,string _tipo, string _cor, int _numPortas){
            this->cor = _cor;
            this->placa = _placa;
            this->tipo = _tipo;
            setNumPortas(_numPortas);
        }

        //todo: verificar porque não foi invocado
        ~Carro(){
            cout << "Carro " << placa << "Destruido!!" << endl;
        }

        void setNumPortas(int numPortas){
            
            if(this->numPortasIsValid(numPortas))
                this->numPortas = numPortas;
            else{
                cout << "número de portas inválido, atribuindo 1" << endl;
                this->numPortas = 1;
            }
            //this->numPortas =  (this->numPortasIsValid(numPortas)) ? numPortas : 1;
        }

        int getNumPortas(){
            return this->numPortas;
        }

        void acelerar(float velocidade){
            cout << "acelerando para " << velocidade << endl;
        }

        void frear(){
            cout << "freando" << endl;
        }
};

class Hatch : public Carro{
    public:
    void imprimirNumPortas(){
        cout << getNumPortas() << endl;
    }
};

int main(){
    Carro *civic = new Carro("OUP-4062","Sedan","Cinza",4);

    cout << civic->tipo << endl;
    cout << civic->getNumPortas() << endl;
    cout << civic->cor << endl;
    cout << civic->placa << endl;


    civic->acelerar(80);
    civic->frear();

    //todo:verificar porque destrutor não foi acionado
    delete(civic);
/*
    Hatch *carro1;   

    carro1->setNumPortas(4);
    carro1->imprimirNumPortas();
*/
    return 0;
}