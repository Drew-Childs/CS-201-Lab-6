#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));			//calculates distance between points
}

int main() {
	vector<double> distance;
	ifstream file_in("input.txt");		//opens and declares files and variables
	ofstream file_out("output.txt");
	ofstream file_sort("output_sorted.txt");
	int x1, x2, y1, y2, z1, z2;

	while (file_in.good()) {
		file_in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;		//reads values from input file
		distance.push_back(calcDistance(x1, y1, z1, x2, y2, z2));		//puts new value at back of vector
		file_out << distance.back() << endl;		//puts new value in output file
	}

	sort(distance.begin(), distance.end());		//function found at http://www.cplusplus.com/reference/algorithm/sort/

	for (int i = 0; i < distance.size(); i++) {		//puts new values in file_sort
		file_sort << distance.at(i) << endl;
	}

	file_in.close();		//closes all files
	file_out.close();
	file_sort.close();
	return 0;
}