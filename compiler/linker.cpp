#include <fstream>
#include <vector>
#include <cstdint>
#include "linker.h"
#include <iostream>
using namespace std;
int main(int argc,char**argv) {
	if (argc<3) {
		return 1;
	}
	vector<uint8_t> input;
	for (int i = 1;i<(argc-1);++i) {
		ifstream fin(argv[i],ios::in|ios::binary);
		if (!fin) {
			return 1;
		}
		fin.unsetf(std::ios::skipws);
		for (uint8_t i;fin>>i;) {
			input.push_back(i);
		}
		fin.close();
	}
	vector<uint8_t> output = link(input);
	ofstream fout(argv[argc-1],ios::out|ios::binary);
	fout.write((char*)&output[0],output.size());
	fout.close();
	return 0;
}
