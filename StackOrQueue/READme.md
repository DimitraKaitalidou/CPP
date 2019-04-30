# Stack or Queue

This is a C++ implementation of two data structures, i.e., a stack and a queue. At first, the program asks if a stack or a queue should be created. Then, the program asks for action selection which allows the management of the data structure that was created through keyboard inputs.

## Implementation details
 
There is a dedicated object for each data structure, the stack and the queue. However, because the structures share a  similar implementation approach, a parent object called "Structure" is implemented to be inherited to the two child objects. 

At the beginning of the program the available selections are:
- 0 for Stack
- 1 for Queue
- q for quit

Then, the available actions for data structure management are:
- Stack:
  - 0 for Exit
  - 1 for Push
  - 2 for Pop
  - 3 for Results
- Queue:
  - 0 for Exit
  - 1 for Insert
  - 2 for Remove
  - 3 for Results

## References
1. https://en.wikibooks.org/wiki/Data_Structures/Stacks_and_Queues
