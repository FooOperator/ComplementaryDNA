// ComplementaryDNA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
class DNA;
class DNA
{
public:
	DNA(const std::string& dna)
	{
		_dna = dna;
	}
	std::vector<char> getComplementaryStrand();
	void strandToString(const std::vector<char>& strand);
private:
	std::string _dna;
	std::map<char, char> my_map = {
		{ 'T', 'A' },
		{ 'A', 'T' },
		{ 'G', 'C' },
		{ 'C', 'G' }
	};
};

int main()
{
	DNA dna("TAGCA");
	DNA dna2("AAAAA");
	dna.getComplementaryStrand();
	dna2.getComplementaryStrand();
}

std::vector<char> DNA::getComplementaryStrand()
{
	char dnaToArray[1024];
	std::vector<char> strand = {};
	strcpy_s(dnaToArray, _dna.c_str());
	for (auto& ch : _dna) {
		strand.push_back(my_map[ch]);
	}
	strandToString(strand);
	return strand;
}
void DNA::strandToString(const std::vector<char>& strand){
	for (auto x : strand) {
		std::cout << x;
	}
	std::cout << std::endl;
}