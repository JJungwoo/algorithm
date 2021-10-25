/*
[LeetCode] 155. Min Stack
https://leetcode.com/problems/min-stack/
*/

class MinStack {

    Stack<Node> stack;
    
    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        int tmp = val;
        if (!stack.isEmpty()) {
            tmp = Math.min(tmp, stack.peek().minValue);
        }
        stack.push(new Node(val, tmp));
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().value;
    }
    
    public int getMin() {
        return stack.peek().minValue;
    }
    
    class Node {
        int value;
        int minValue;
        Node (int v, int mv) {
            this.value = v;
            this.minValue = mv;
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
