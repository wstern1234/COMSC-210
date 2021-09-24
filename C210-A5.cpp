#include <iostream>
#include <string>

using namespace std;




void TowersOfHanoi(int num, char source, char aux, char des)
{
	if (num == 1)
	{
		cout << "Move a disk from " << source << " to " << des << endl;
		return;
	}

	TowersOfHanoi(num - 1, source, des, aux);
	cout << "Move a disk from " << source << " to " << des << endl;
	TowersOfHanoi(num - 1, aux, source, des);
}

int main() {

	string buffer;
	int numDisks;

	cout << "Enter a number of disks to play: ";
	cin >> buffer;

	numDisks = stoi(buffer);

	TowersOfHanoi(numDisks, 'A', 'B', 'C');


	return 0;
}