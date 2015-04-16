#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <map>

class VirtualMemorySimulator{
	private:
		struct process{
		//	int pid;
			int num_pages;
			std::vector<int> pages;
		};

		// This struct will contain info such as age for LRU, size if needed
		// and everything else for the page replacement algorithms
		// frame.pid will be -1 for unallocated frames
		struct frame{
			int pid; // The process the frame is allocated to
			frame(int p)
			: pid(p){}
		};

		// The vector of frame structs representing physical memory
		std::vector<frame> physical_memory;

		// Format for physical_memory is pair<pid, page>
		//std::vector< std::pair<int, int>> physical_memory;

		// pair format is <pid, process>
		std::map<int,struct process> virtual_memory;

	public:
		VirtualMemorySimulator(int num_frames);
		void start(int pid, int size);
		void terminate(int pid);
		int reference(int pid, int page_number);
};
