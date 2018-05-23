#include "stdafx.h"
#include <iostream>
#include "silhouette.h"
#include <ctime>

using namespace std;

int main() {
	cout << Silhouette() << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	system("pause");
	return 0;
}