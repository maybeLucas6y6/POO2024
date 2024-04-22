class PriorityQueue {
    int capacity, size;
    int* data;
public:
    PriorityQueue(int max_size);
    ~PriorityQueue();
    PriorityQueue& operator+=(int val);
    operator int();
    int operator--(int val); 
    int operator()(const char* key); 
};
