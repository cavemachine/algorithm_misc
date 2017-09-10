#include <iostream>
using namespace std;

int N[10] = {0,1,2,3,4,5,6,7,8,9};

void nod(int p, int q) {
    cout << "p: " << p << "\n";
    cout << "q: " << q << "\n";

    while (N[q] != q) {
	q = N[q];
    }
    while (N[p] != p) {
	p = N[p];
    }
    N[p] = q;
    
    
    for (int x = 0; x < 10; ++x) {
	cout << N[x];
	cout << " ";
    }
    cout << "\n";
}

int main (){

    nod(4,3); // 2 becomes child of 3
    nod(3,8);
    nod(6,5);
    nod(9,4);
    nod(2,1);
    nod(5,0);
    nod(7,2);
    nod(6,1);
    nod(7,3);
}
