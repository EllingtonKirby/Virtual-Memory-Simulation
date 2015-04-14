#include <string>
#include <vector>
#include <utility>
#include <math.h>

class VirtualMemorySimulator{
	private:
		struct process{
			int pid;
			int num_pages;
			std::vector<int> pages;
		};
		std::vector< std::pair<int, int>> physical_memory;
		std::map<int,struct process> virtual_memory;
	public:
		VirtualMemorySimulator(int num_frames);
		void start(int pid, int size);
		void terminate(int pid);
		void reference(int pid, int page_number);

};
