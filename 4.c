//Сначала мы создадим структуру Node, которая будет представлять узел списка:
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//Затем мы создадим структуру Stack, которая будет содержать вершину стека:
typedef struct Stack {
    Node* top;
}Stack;
//Теперь реализуем основные функции работы со стеком:

//Добавление значения в стек:
void push(Stack* stack, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));  // создаем новый узел
    if(newNode == NULL) {
        printf("Стек переполнен\n");
        return;
    }
    newNode->data = value;  // присваиваем значение узлу
    newNode->next = stack->top;  // устанавливаем ссылку на предыдущий узел
    stack->top = newNode;  // делаем новый узел вершиной стека
}
//Извлечение значения из стека:
void pop(Stack* stack) {
    if(stack->top == NULL) {
        printf("Стек пуст\n");
        return;
    }
    Node* temp = stack->top;  // сохраняем ссылку на текущую вершину
    stack->top = stack->top->next;  // делаем следующий узел вершиной стека
    free(temp);  // освобождаем память узла
}
//Просмотр верхнего значения стека:
int peek(Stack* stack) {
    if(stack->top == NULL) {
        printf("Стек пуст\n");
        return -1;  // возвращаем значение по умолчанию
    }
    return stack->top->data;  // возвращаем значение вершины стека
}
//Теперь мы можем использовать эти функции для работы со стеком:
int main() {
    Stack stack;
    stack.top = NULL;  // инициализируем стек
    
    push(&stack, 10);  // добавляем значение в стек
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Верхнее значение стека: %d\n", peek(&stack));  // просмотр верхнего значения стека
    
    pop(&stack);  // извлекаем значение из стека
    printf("Верхнее значение стека: %d\n", peek(&stack));
    
    return 0;
}
//Здесь мы добавляем значения 10, 20 и 30 в стек, 
//затем просматриваем верхнее значение стека (30), 
//а затем извлекаем значение из стека и просматриваем верхнее значение снова (20)