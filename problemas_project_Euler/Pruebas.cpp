#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
//Ver patron de primos imprimiendo

using namespace std;

void cribaEratostenes(long long int n);
void criba2(long long int n);
template <typename TipoDato>
void printVector(vector<TipoDato> v);
int P6_difCuadrados(int n);
int P8_AdjacentProduct(string numero);


int main(){
    string num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    //2091059712
    string num2 = "863465674813919123162824586178664583591245665294765456828489128831426";
    //2090188800
    cout << P8_AdjacentProduct(num) << endl;
    return 0;
}



int P6_difCuadrados(int n){
    //Diferencia entre la suma de los primero n numeros al cuadrado y la suma de los cuadrados de los 1eros n numeros
    // 1) suma de cuadrados:
    int s1 = 0;
    for (int i = 1; i < n+1; i++){
        s1 = s1+ pow(i,2);
    }
    // 2) Cuadrado de la suma
    int s2 = pow(n*(n+1)/2,2);
    return s2 - s1+1;
}

int P8_AdjacentProduct(string numero){
    //Para pasar de ascii a entero: -48
    if(numero.size() < 13){
        cerr << "INPUT NO TIENE 13 O MAS CARACTERES" << endl;
        return -1;
    }
    int candidatos[13];
    int low = 0;
    int idxDer = 13; // indice bandera
    
    //Volviendo de Ascii a numero original
    int numbers[numero.size()];
    for(int i = 0; i < numero.size(); i++){
        numbers[i] = int(numero[i])-48;
        cout << numbers[i] << "|";
    }
    cout << '\n' << endl;


    //Pasando priemros candidatos
    for(int i = 0; i < 13; i++){
        candidatos[i] = numbers[i];
        }
    
    
    //Primera multiplicacion
    int p = 1;
    for (int i = low; i < idxDer; i++){
        p = p*candidatos[i];
    }

    int max = p;
    while(idxDer <= numero.size()){
        p = 1;
        cout << "low: " << low << endl;
        cout << "idxDer: " << idxDer << endl;
        cout << "candidatos:" << endl;
        for (int i = low; i < idxDer; i++){
            //cout << "numbers[i]: " << numbers[i] << endl;
            //candidatos[i-low] = numbers[i];
            cout << numbers[i] << "|";
            if(numbers[i] == 0){
                p = 0;
                cout << "p: " << p << endl;
                break;
            }
            p = p*numbers[i];
        }
        cout << "p: " << p << endl;
        cout << '\n' << endl;
    if(p >= max){
        max = p;
    }
    low++;
    idxDer++;
    cout << "Maximo: " << max << endl;
    cout<< "========================================" << endl;
    }
    return max;

}



void cribaEratostenes(long long int n){
    vector<bool> marcados;
    for(int i = 2; i < n; i++){
        marcados.push_back(false);
    }
    
    for(int i = 0; i < floor(sqrt(n)); i++){
        if(marcados[i] == false){
            
            for(int j = i+2; j < n/(i+2) ; j++){
                marcados[(i+2)*j-2] = true;
                
            }
            
        }

    }
    //el indice de marcados + 2 da el numero real
    vector<int> primos;
    for(int i = 0; i < marcados.size(); i++){
        if(marcados[i] == false){
            primos.push_back(i+2);
        }  
    }
    
    //printVector(primos);
    return;
    int idx = floor(sqrt(n));
    while(n % primos[idx] != 0){
        idx--;
        if(idx < 0){
            cout << "NO HAY DIVISOR" << endl;
            return;
        }
        
    }
    cout << primos[idx] << endl;
    cout << "FACTOR MAS GRANDE PRIMO DE "<< n<<": "<< primos[idx] << endl;

}

template <typename TipoDato>
void printVector(vector<TipoDato> v){
    cout << "i" <<"|"<< "v[i]" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << i << "|" << v[i] << endl;
    }
}
