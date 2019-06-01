#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//Ver patron de primos imprimiendo

using namespace std;

void cribaEratostenes(long long int n);
void criba2(long long int n);
template <typename TipoDato>
void printVector(vector<TipoDato> v);

int main(){
    long long int n = 600851475143;
    long long int m = 13195;
    vector<int> v;
    cribaEratostenes(m);
    return 0;
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
