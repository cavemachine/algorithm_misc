#include <iostream>
using namespace std;

bool connected(int p,int q);
void node(int p,int q);

int points = 10;
int N[10];

int main(){
    
    for (int x = 0; x < points; ++x) {
	N[x] = x;
    }

    int p;
    int q;
    while (1){
	cout << "Enter 'p': ";
	cin >> p;
	cout << "Enter 'q': ";
	cin >> q;
	node(p,q);
    }    
}

bool connected(int p, int q) {
    if (N[p-1] == N[q-1]) {
	return true;
    } else { 
	return false;
    }
}

void node(int p, int q) {
// Change ALL array 'p's values to q
    for (int x = 0; x < 10; ++x) {
	if (N[x] == p) {
	    N[x] = q;
	}
	cout << N[x];
	cout << " ";
    }
    cout << '\n';
    
}
