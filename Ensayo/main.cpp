#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int n);
vector<int> Primes(int n);
int LargestPrimeFactor(int n);
long int CribaEratostenes(long long int n);

int main(){
    int n = 12;
    //cout << n << " es primo ? " << isPrime(n) << endl;
    vector<int> v = Primes(20);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    int x = LargestPrimeFactor(15);
    cout << "divisor mas grande primo: " << x << endl;

    //int l = LargestPrimeFactor(n);
    //cout << "Divisor primo mas grande de " << endl;
    //cout << l <<  endl;

}

bool isPrime(int n){
    if(n <= 1){
        return false;
    }else
    {
        int i = 2;
        while(i < n){
            if(n % i == 0){
                return false;
            }
            i++;
        }
        return true;
    }

}
vector<int> Primes(int n){
    vector<int> v;
    for(int i = 2; i < n; i++){
        if(isPrime(i) == true){
            v.push_back(i);
        }
    }

    return v;
}

int LargestPrimeFactor(int n){
    //Retorna el divisor primo mas grande de n
    if(isPrime(n) == true){
      return -1;
    }
    vector<int> v = Primes(n);
    vector<int> div;
    cout << "tamaño: " << v.size() << endl;
    for(int i = 0;i < v.size()-1; i++){
        cout << "v[i]: " << v[i] << endl;
        if (n % v[i] == 0) {
            cout << v[i] << endl;
            div.push_back(v[i]);
        }

    }

    return div[div.size()-1];

}


long int CribaEratostenes(long long int n){
  //revisar TODO;
  vector<bool> v;
  //Suponemos que todos los enteros son primos
  for(int i = 2; i < n i++){
    v.push_back(true);
  }
  int idx = 0;
  int div = v[idx];
  while(v[idx] <= (n**0.5)){
    for(int i = idx; i < n; i++){
      if(n%v[i] == 0){

      }
    }

  }

}
