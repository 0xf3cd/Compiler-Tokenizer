#include "Tokenizer.h"
#include <iostream>
using namespace std;

int main() {
	Tokenizer T;
	T.openSourceFile("./example.cmm");
	if(!T.hasOpen()) {
		cout << "Failed to open." << endl;
		return -1;
	}

	while(true) {
		word x = T.readNextWord();
		if(x.type < 0) {
			break;
		}
		cout << x.line_num << '\t' << x.start_char_num << '\t' << x.end_char_num << '\t' << x.type << '\t' << x.value << endl;
	}

	cout << T.hasReadPound() << endl;
	cout << T.hasMistake() << endl;

	return 1;
}
