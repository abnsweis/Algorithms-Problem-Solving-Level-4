#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace MyStringlib {

	string LowerAllString(string str) {

		for (int i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}

		return str;
	}
	string UpperAllString(string str) {

		for (int i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
		}

		return str;
	}


	vector < string > split(string str, string delimiter) {

		vector < string > vString;

		short pos = 0;
		string word = "";


		while((pos = str.find(delimiter)) != std::string::npos) {

			word = str.substr(0, pos);

			if(word != "") {
				vString.push_back(word);
			}

			str = str.erase(0, pos + delimiter.length());

		}

		if(word != "") {
			vString.push_back(str);
		}


		return vString;
	}

	char InvertCharCase(char character) {

		return character == toupper(character) ? tolower(character):
		toupper(character);

	}

	string InvertString(string str) {

		for (int i = 0; i < str.length(); i++) {


			str[i] = InvertCharCase(str[i]);
		}

		return str;
	}


	string ReadString() {
		string str = "";
		cout << "Please Enter Your String : ";
		getline(cin, str);

		return str;
	}

	string join(vector < string > vWwords_p, string delimiter) {

		string NewStr = "";

		for (string &word: vWwords_p) {
			NewStr += word + delimiter;
		}

		return NewStr.substr(0, NewStr.length() - delimiter.length());
	}

	string join(string arrStr[], int arrlength, string delimiter) {
		string NewStr = "";

		for (int i = 0; i < arrlength; i++) {
			NewStr += arrStr[i] + delimiter;
		}
		return NewStr.substr(0, NewStr.length() - delimiter.length());
	}



	string trimleft(string str) {


		for (int i = 0; i < str.length(); i++) {

			if(str[i] != ' ') {
				str.erase(0, i);
			}

		}
		return str;
	}


	string trimright(string str) {
		for (int i = str.length() - 1; i > 0; i--) {

			if(str[i] != ' ') {
				return str.erase(i+1, str.length());
			}

		}
		return str;
	}


	string trim(string str) {
		return trimright(trimleft(str));
	}

string replceWord(string S1,string WordToReplce,string NewWord){
	
	short pos = S1.find(WordToReplce);
	
	
	while(pos != std::string::npos){
		
		S1 = S1.replace(pos,WordToReplce.length(),NewWord);
		pos = S1.find(WordToReplce);
		
	}
	
	return S1; 
}

}