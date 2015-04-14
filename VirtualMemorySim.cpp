#include "VirtualMemorySimulator.h"
using namespace std;

VirtualMemorySimulator::VirtualMemorySimulator(int num_frames){
	//initialize physical memory to -1, representing vacant
	for(int i = 0; i < num_frames; i++){
		physical_memory.push_back(pair<int, int>(-1,-1));
	}
}

void VirtualMemorySimulator::start(int process_id, int size){
	struct process p1;
	p1.pid = process_id; //this may be unnecessary
	p1.num_pages = size;
	for(int i = 0; i < num_pages; i++){
		//vector pages represents a processes address space
		//each index represents a page
		//a value of -1 represents 
		p1.pages.push_back(-1);
	}
	virtual_memory.push_back(pair<process_id, p1>);
}
