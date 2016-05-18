
MinMaxHeap::MinMaxHeap() {
	for (int i = 0; i < 500; i++) {
		heap_arr[i] = INT_MAX; // need to have a default value
	}
}

MinMaxHeap::MinMaxHeap(std::string input_file) {
	for (int i = 0; i < 500; i++) {
		heap_arr[i] = -1; // need to have a default value
	}
	std::ifstream infile;
	infile.open ("data.txt");
    std::string line;
    while(std::getline(infile, line)){
        std::stringstream  lineStream(line);
        int value;
        while(lineStream >> value){
        	heap_arr[num_nodes] = value;
        	num_nodes++;
        }
    }
    infile.close();

	for (int i = num_nodes-1; i >= 0; i--) {
		reHeap(i);
	}
}

bool MinMaxHeap::is_empty(){
	return num_nodes == 0;
}

bool MinMaxHeap::isminlevel(int location) {
	return int(trunc(log2(location+1)))%2==0;
}

void MinMaxHeap::insert(int x) {
	heap_arr[num_nodes] = x;
	num_nodes++;
	for (int i = (num_nodes-1)/2; i >= 0; i--) {
		reHeap(i);
	}
}

bool MinMaxHeap::insert_helper(int x, int parent, int cur_loc) {
	if (isminlevel(cur_loc)) {
		if (x < heap_arr[parent]) {
			heap_arr[cur_loc] = heap_arr[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap_arr[cur_loc] = x;
		}
	} else {
		if (x > heap_arr[parent]) {
			heap_arr[cur_loc] = heap_arr[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap_arr[cur_loc] = x;
		}
	}
}

void MinMaxHeap::remove(int x) {
	for (int i = 0; i <= num_nodes; i++) {
		if (heap_arr[i] == x) {
			if (i != num_nodes - 1) {
				std::cout << "nope\n";
				heap_arr[i] = heap_arr[num_nodes - 1];
				heap_arr[num_nodes-1] = INT_MAX;
				num_nodes--;
				for (int i = (num_nodes-1)/2; i >= 0; i--) {
					reHeap(i);
				}
			} else {
				heap_arr[num_nodes-1] = INT_MAX;
				num_nodes--;
			}
			break;
		}
	}
}

void MinMaxHeap::delete_min() {
	remove(heap_arr[0]);
}

void MinMaxHeap::delete_max() {
	remove(std::max(heap_arr[1], heap_arr[2]));
}

void MinMaxHeap::level_order(){
	if (num_nodes > 0)
		std::cout << heap_arr[0];
	int j = 1;
	int count = 1;
	for(int i = 2; i <= num_nodes; i++){
		if(count == j){
			std::cout << "\n" << heap_arr[i-1] << " ";
			j = j*2;
			count = 1;
		}else{
			count++;
			std::cout << heap_arr[i-1] << " ";
		}
	}
}

bool MinMaxHeap::search(int x) {
	for (int i = 0; i < num_nodes; i++) {
		if (heap_arr[i] == x)
			return true;
	}
	return false;
}

void MinMaxHeap::reHeap(int loc) {
	std::cout << "location: " << loc << " num_nodes: "<< num_nodes << " data: " << heap_arr[loc] << std::endl;
	int comp = 2*loc+1; // fill in with a default value
	if (2*loc+1 >= num_nodes)
		return;

	for(int i = 1; i <= 2; i++) {
		if (isminlevel(loc)) {
			if (heap_arr[2*loc+i] < heap_arr[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap_arr[2*(2*loc+i)+j] < heap_arr[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		} else {
			if (heap_arr[2*loc+i] > heap_arr[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap_arr[2*(2*loc+i)+j] > heap_arr[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		}
	}

	if (isminlevel(loc)) {
		if (heap_arr[comp] < heap_arr[loc]) {
			int tmp = heap_arr[loc];
			heap_arr[loc] = heap_arr[comp];
			heap_arr[comp] = tmp;
			reHeap(loc);
			reHeap((comp-1)/2);
			reHeap(comp);
		}
	} else {
		if (heap_arr[comp] > heap_arr[loc]) {
			int tmp = heap_arr[loc];
			heap_arr[loc] = heap_arr[comp];
			heap_arr[comp] = tmp;
			reHeap(loc);
			reHeap((comp-1)/2);
			reHeap(comp);
		}
	}
}

void TrickleDown(int i)
{
	if ( isminlevel(i) )
	{
		TrickleDownMin(i);
	}
	else
	{
		TrickleDownMax(i);
	}
}//TrickleDown

void TrickleDownMin(int i)
{
	if ( hasChildren(i) )
	{
		int m = 
	}//if - hasChildren

}//TrickleDownMin

void TrickleDownMax(int i)
{

}//TrickleDownMax

bool hasChildren(int i)
{
	int child = 2*i+1;
	if ( child != INT_MAX )
		return true;
	else
		return false;
}//hasChildren

int smallestChild(int i)
{
	int child1 = 2*i+1;
	int child2 = 2*i+2;
	for(int x = 1; x <= 2; x++) 
	{
		for(int x = 1; x <= 2; x++)
		{

		}//for - each grandchild
	}//for - each child
}//smallestChild