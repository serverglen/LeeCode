/**
 * 232. 用栈实现队列
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

 * 实现 MyQueue 类：
 * 
 * void push(int x) 将元素 x 推到队列的末尾
 * int pop() 从队列的开头移除并返回元素
 * int peek() 返回队列开头的元素
 * boolean empty() 如果队列为空，返回 true ；否则，返回 false
 *  
 * 
 * 说明：
 * 
 * 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *  
 * 
 * 进阶：
 * 
 * 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 *  
 * 
 * 示例：
 * 
 * 输入：
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 1, 1, false]
 * 
 * 解释：
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 * 
 * 解题思路：
 *  两个栈 front和back
 *  front 用于输入栈，用于push数据
 *  back  用于输出栈，用于pop和top数据。
 * 
 * push的时候将数据直接push到front中。
 * 
 * top的时候先检查back栈是否为空
 *      如果不为空直接top back栈
 *      如果为空，则将遍历front，将其所有元素都push到back中。
 *          然后top back栈顶元素
 * 
 * pop同top逻辑类似
 *      如果不为空直接pop back栈
 *      如果为空，则将遍历front，将其所有元素都push到back中。
 *          然后top back栈顶元素保存起来，用于返回
 *          然后pop back栈顶元素
 * 
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        front.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (back.empty()) {
            front2back();
        }
        int ret = back.top();
        back.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (back.empty()) {
            front2back();
        }
        return back.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return front.empty() && back.empty();
    }

private:
    void front2back() {
        while(!front.empty()) {
            back.push(front.top());
            front.pop();
        }
    }

private:
    std::stack<int> front;
    std::stack<int> back;
    int size;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */