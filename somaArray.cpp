#include <vector>
#include <thread>
#include <iostream>



#define ll long long
using namespace std;

void acumulaRange(ll &soma, ll inicio, ll fim) {
  soma = 0;
  for (ll i = inicio; i < fim; i++){
    soma += i;
  } 
}

int main() {
  const int numeroThreads = 2;
  const int numeroElementos = 1000000000;
  const int passo = numeroElementos / numeroThreads; // metade para cada lado

  vector<ll> somaParcial(numeroThreads);

  thread t1(acumulaRange, ref(somaParcial[0]), 0, passo);
  thread t2(acumulaRange, ref(somaParcial[1]), passo, numeroThreads*passo);

  t1.join();
  t2.join();

  ll total = somaParcial[0] + somaParcial[1];

  cout << total << '\n';

  return 0;

}