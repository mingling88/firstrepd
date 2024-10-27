#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<iostream>
#define MAX_SIZE 100


//typedef struct {
//    char data[MAX_SIZE];
//    int top;
//} SeqStack;
//
//
//void initStack(SeqStack* stack) {
//    stack->top = -1;
//}
//
//
//bool isEmpty(SeqStack* stack) {
//    return stack->top == -1;
//}
//
//
//bool push(SeqStack* stack, char item) {
//    if (stack->top < MAX_SIZE - 1) {
//        stack->data[++stack->top] = item;
//        return true;
//    }
//    return false; 
//}
//
//
//bool pop(SeqStack* stack, char* item) {
//    if (!isEmpty(stack)) {
//        *item = stack->data[stack->top--];
//        return true;
//    }
//    return false; 
//}
//
//
//bool isBalanced(char* expr) {
//    SeqStack stack;
//    initStack(&stack);
//
//    for (int i = 0; expr[i] != '\0'; i++) {
//        char current = expr[i];
//        if (current == '(') {
//            push(&stack, current);
//        }
//        else if (current == ')') {
//            if (isEmpty(&stack)) {
//                return false; 
//            }
//            char temp;
//            pop(&stack, &temp);
//        }
//    }
//
//    return isEmpty(&stack); 
//}
//
//int main() {
//    //const char* expression = "((a + b) * (c - d))"; 
//    char exp[20];
//    char* ptr = exp;
//    std::cin.getline(ptr,19);
//    if (isBalanced(ptr)) {
//        printf("括号配对正确。\n");
//    }
//    else {
//        printf("括号配对不正确。\n");
//    }
//    return 0;
//}
//
//
///*#include <stdio.h>
//#include <stdlib.h>
/*#include <stdbool.h>

#define MAX_SIZE 100


typedef struct {
    int data[MAX_SIZE];
    int front; 
    int rear;  
} CircularQueue;


void initQueue(CircularQueue* queue) {
    queue->front = 0;
    queue->rear = 0;
}


bool isEmpty(CircularQueue* queue) {
    return queue->front == queue->rear;
}


bool isFull(CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}


bool enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("队列已满，无法入队 %d。\n", item);
        return false; 
    }
    queue->data[queue->rear] = item;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return true;
}


bool dequeue(CircularQueue* queue, int* item) {
    if (isEmpty(queue)) {
        printf("队列为空，无法出队。\n");
        return false; // 队列空
    }
    *item = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return true;
}


void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}



int main() {
    CircularQueue queue;
    initQueue(&queue);
    int input;

    printf("请输入整数序列 (输入 0 结束)：\n");
    while (true) {
        //scanf("%d", &input);
        std::cin >> input;
        if (input == 0) {
            break; 
        }
        else if (input > 0) {
            enqueue(&queue, input); 
        }
        else if (input < 0) {
            int item;
            if (dequeue(&queue, &item)) {
                printf("出队元素: %d\n", item);
            }
        }
    }
    printf("队列：");
    printQueue(&queue);
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100


typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;


typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;


void initStack(Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

bool push(Stack* stack, int item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = item;
        return true;
    }
    return false; 
}

bool pop(Stack* stack, int* item) {
    if (!isStackEmpty(stack)) {
        *item = stack->data[stack->top--];
        return true;
    }
    return false; 
}


void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

bool isQueueFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

bool enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        return false; 
    }
    queue->data[queue->rear] = item;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return true;
}

bool dequeue(Queue* queue, int* item) {
    if (isQueueEmpty(queue)) {
        return false; 
    }
    *item = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return true;
}


void reverseQueue(Queue* queue) {
    Stack stack;
    initStack(&stack);

    
    while (!isQueueEmpty(queue)) {
        int item;
        dequeue(queue, &item);
        push(&stack, item);
    }

   
    while (!isStackEmpty(&stack)) {
        int item;
        pop(&stack, &item);
        enqueue(queue, item);
    }
}


void printQueue(Queue* queue) {
    int index = queue->front;
    while (index != queue->rear) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main()
{
    Queue que;
    initQueue(&que);
    int n,m;
    printf("输入队列中的数目：\n");
    std::cin >> n;
    printf("输入队列：\n");
    for (int i = 0;i < n;i++)
    {
        std::cin >> m;
        enqueue(&que, m);
    }
    reverseQueue(&que);
    printf("逆转后的队列：");
    printQueue(&que);
    return 0;
}