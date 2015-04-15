#include "VirtualMemorySimulator.h"
using namespace std;
#define FREE_FRAME -1

VirtualMemorySimulator::VirtualMemorySimulator(int num_frames){
	//initialize physical memory to -1, representing vacant
	//physical_memory size represents
	for(int i = 0; i < num_frames; i++){
		//physical_memory.push_back(pair<int, int>(-1,-1));

		struct frame f(FREE_FRAME);
		physical_memory.push_back(f);
	}
}

void VirtualMemorySimulator::start(int process_id, int size){
	struct process p1;
	//p1.pid = process_id; //this may be unnecessary
	p1.num_pages = size;
	for(int i = 0; i < num_pages; i++){
		//vector pages represents a processes address space
		//each index represents a page
		//a value of -1 represents a null reference
		p1.pages.push_back(-1);
	}
	virtual_memory.push_back(pair<process_id, p1>);
}

// Return Values:
// 0 - Page fault
// 1 - Success
// 2 - Page already resident to process
int VirtualMemorySimulator::reference(int pid, int page_number){
	// Check if the page is not resident
	bool resident = false;
	struct process p = virtual_memory[pid];
	for(auto it : p.pages){
		if(it == page_number)
			resident = true;
	}

	// If the page number is not resident, check for available memory
	if(!resident){
		for(int i = 0; i < physical_memory.size(); i++){
			if(physical_memory[i].pid == FREE_FRAME){
				p.pages.push_back(i);
				physical_memory[i].pid = pid;
				return 1;
			}
		}

		// If we get to this point, there is a page fault (no frames available)
		return 0;
	}
	else{
		// Page is already resident to pcoess
		return 2;
	}
}

void VirtualMemorySimulator::terminate(int process_id){
	// Free all frames the process references
	for(auto f : physical_memory){
		if(f.pid == process_id){}
			// Deallocate the frame
			f.pid = FREE_FRAME;
		}
	}

	// Remove the process from the map
	auto p = virtual_memory.find(process_id);
	if(p != virtual_memory.end())
		virtual_memory.erase(p);
}