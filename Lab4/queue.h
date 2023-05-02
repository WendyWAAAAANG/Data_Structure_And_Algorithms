//structure declaration.
typedef struct{
       double* values;
       int front;
       int rear;
       int counter;
       int maxSize;
} Queue;

//function declaration.
bool CreateQueue(Queue *queue, int size);
/* function: creates a new queue array and initializes the queue data structure
   input: queue: pointer to the queue data structure
          size: maximum size of the queue
   output: a boolean indicating whether the creation succeeded or not
*/

bool IsEmpty(Queue* queue);
/* function: checks whether a queue is empty or not
   input: queue: pointer to the queue data structure
   output: a boolean indicating whether the queue is empty
*/

bool IsFull(Queue* queue);
/* function: checks whether a queue is full or not
   input: queue: pointer to the queue data structure
   output: a boolean indicating whether the queue is full
*/

bool Enqueue(Queue* queue, double x);
/* function: adds a new value at the end of the queue
   input: queue: pointer to the queue data structure
          x: the new value to be added
   output: a boolean indicating whether the enqueue succeeded
*/

bool Dequeue(Queue* queue, double* x);
/* function: reads and removes the front value from the queue
   input: queue: pointer to the queue data structure
          x: pointer to the variable in which the front value will be written
   output: a boolean indicating whether the dequeue succeeded
*/

void DisplayQueue(Queue* queue);
/* function: prints the content of the queue
   input: queue: pointer to the queue data structure
   output: none
*/

void DestroyQueue(Queue** queue);
/* function: frees the memory used by the queue's array and resets the queue data structure
   input: queue: pointer to the queue data structure
   output: none
*/