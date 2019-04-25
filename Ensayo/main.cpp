#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(long long int n);
vector<int> Primes( long long int n);
int LargestPrimeFactor(long long int n);

int main(){
    //long long int n = 600851475143;
    long long int n = 1000000;
    int x = LargestPrimeFactor(n);
    cout << "divisor mas grande primo de " << n << ": " << x << endl;


}

bool isPrime(long long int n){
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
vector<int> Primes(long long int n){
    vector<int> v;
    for(int i = 2; i < n; i++){
        if(isPrime(i) == true){
            v.push_back(i);
        }
    }

    return v;
}

int LargestPrimeFactor(long long int n){
    //Retorna el divisor primo mas grande de n
    if(isPrime(n) == true){
      return -1;
    }
    vector<int> v = Primes(n);
    vector<int> div;
    for(int i = 0;i < v.size()-1; i++){
        if (n % v[i] == 0) {
            cout << v[i] << endl;
            div.push_back(v[i]);
        }

    }

    return div[div.size()-1];

}
