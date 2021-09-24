#include <iostream>
#include <string>

using namespace std;




// calculates moves for disks
void TowersOfHanoi(int num, char source, char aux, char dest)
{
  // if num is 1, move disk to dest
	if (num == 1)
	{
		cout << "Move a disk from " << source << " to " << dest << endl;
		return;
	}

  // 2 recursive choices, either source, dest, aux or aux, source, dest
	TowersOfHanoi(num - 1, source, dest, aux);
	cout << "Move a disk from " << source << " to " << dest << endl;
	TowersOfHanoi(num - 1, aux, source, dest);
}





int main() {

  // buffer for input, total number of disks
	string buffer;
	int numDisks;

	cout << "Enter a number of disks to play: ";
	cin >> buffer;

  // converts string input to int
	numDisks = stoi(buffer);

	TowersOfHanoi(numDisks, 'A', 'B', 'C');


	return 0;
}
