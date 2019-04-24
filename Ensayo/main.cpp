#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int n);
vector<int> Primes(int n);
int LargestPrimeFactor(int n);

int main(){
    int n = 11;
    /*
    //cout << n << " es primo ? " << isPrime(n) << endl;
    vector<int> v = Primes(20);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ", " ;
    }
    cout << endl;
    */
    int l = LargestPrimeFactor(n);
    cout << "Divisor primo mas grande de " << n << endl;
    cout << l <<  endl;
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
    vector<int> v = Primes(n);
    vector<int> div;
    for(int i = 0;i < v.size(); i++){
        if (n % v[i] == 0) {
            cout << v[i] << endl;
            div.push_back(v[i]);
        }
        
    }

    return div[div.size() - 1];

}