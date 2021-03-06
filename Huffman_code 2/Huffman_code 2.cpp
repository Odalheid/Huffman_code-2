#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int letters_num, encoded_length;
	cin >> letters_num >> encoded_length;
	map<string, string> huffman_code;
	for (int j = 0; j < letters_num; ++j) {
		string letter, code;
		cin >> letter >> code; // a: 0	letter = "a:" , code = 0
		huffman_code[code] = string(1, letter[0]);
	}
	string encoded_word;
	cin >> encoded_word;
	string init_word;
	for (int j = 0; j < encoded_length;) {
		string tmp = "";
		while (huffman_code[tmp] == "") {
			tmp += encoded_word[j];
			++j;
		}
		map<string, string>::iterator it = huffman_code.find(tmp);
		init_word += it->second;
	}
	cout << init_word;
    return 0;
}

