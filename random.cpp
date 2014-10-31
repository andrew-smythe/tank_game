#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{  
    srand(time(NULL));
    cout << rand()%2 + 1 << endl;
    return 0;
}
