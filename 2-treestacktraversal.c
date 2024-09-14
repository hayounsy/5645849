class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self, value):
        self.stack.append(value)
    
    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        else:
            return None
    
    def isEmpty(self):
        return len(self.stack) == 0
    
    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            return None

# 전위 순회 함수 (Pre-order)
def preOrderTraversal(stack):
    print("Pre-order Traversal:")
    while not stack.isEmpty():
        print(stack.pop())

# 중위 순회 함수 (In-order)
def inOrderTraversal(stack):
    print("In-order Traversal:")
    # 스택을 다시 초기화하여 중간 항목들을 출력
    stack = initStack()
    for item in stack.stack:
        print(item)

# 후위 순회 함수 (Post-order)
def postOrderTraversal(stack):
    print("Post-order Traversal:")
    # 스택을 다시 초기화하고 역순으로 출력
    stack = initStack()
    stack.stack.reverse()  # 후위 순회를 위해 스택을 역순으로 정렬
    while not stack.isEmpty():
        print(stack.pop())

# 스택 초기화 함수
def initStack():
    stack = Stack()
    stack.push("This is a test of your")
    stack.push('knowledge of "qoutes" used')
    stack.push("in 'string literals.'")
    stack.push('')
    stack.push('You\'re bound to "het it right"')
    stack.push("if you read th section on")
    stack.push("''quotes.''")
    return stack

def main():
    stack = initStack()

    # 전위 순회
    preOrderTraversal(stack)

    # 중위 순회
    inOrderTraversal(stack)

    # 후위 순회
    postOrderTraversal(stack)

main()
