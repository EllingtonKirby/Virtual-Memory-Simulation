#include <fstream>
#include <stringstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "USAGE: ./program2 <frames-of-memory> <input-file>" << endl;
	}
	else{
		string filename(argv[2]);
		int num_frames = atoi(argv[1]);
		//to do: initialize number of frames of memory
		//do so using a class, which contains parameters representing frame size
		//as well as a data structure to store processes
		//processes should be indexed by process number
		ifstream infile(filename);
		if(infile.is_open()){
			string line, word;
			while(getline(infile, line)){
				stringstream ss(line);
				ss >> word;
				if(word == "START"){
					int process_number = 0;
					int address_space_size = 0;
					ss >> process_number;
					ss >> address_space_size;
					//call start proccess function
				}
				else if(word == "TERMINATE"){
					int process_number = 0;
					ss >> process_number;
					//call terminate process function
				}
				else{//REFERENCE
					int process_number = 0;
					int page_number = 0;
					ss >> process_number;
					ss >> page_number;
					//call reference function
				}	
			}
		}
		infile.close();
	}
	return 0;
}
