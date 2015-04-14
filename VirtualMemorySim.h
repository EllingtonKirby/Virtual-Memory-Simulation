#include <string>
#include <vector>
#include <utility>
#include <math.h>

class VirtualMemorySimulator{
	private:
		vector< pair<int, int>> physical_memory;
		vector<int[]> virtual_memory;

	public:
		VirtualMemorySimulator(int num_frames);
		void start(int pid, int size);
		void terminate(int pid);
		void reference(int pid, int page_number);

};
