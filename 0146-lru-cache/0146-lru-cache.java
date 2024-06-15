class LRUCache {
    
    class Node {
        int val;
        Node next;
        Node prev;
        Node(int val, Node next, Node prev) {
            this.val = val;
            this.next = next;
            this.prev = prev;
        }
    }
    
    Map<Integer, Node> keyNodeMap;
    Map<Integer, Integer> keyValueMap;
    Node head;
    Node tail;
    int capacity;
    
    public LRUCache(int capacity) {
        keyNodeMap = new HashMap<>();
        keyValueMap = new HashMap<>();
        head = new Node(-1, null, null);
        tail = head;
        this.capacity = capacity;
    }
    
    public void deleteNode(int key) {
        if(keyNodeMap.containsKey(key)) {   
            Node node = keyNodeMap.get(key);
            keyNodeMap.remove(key);
            keyValueMap.remove(key);
            node.prev.next = node.next;
            if(node.next != null) {
                node.next.prev = node.prev;
            } else
                tail = node.prev;
            node = null;
        }
    }
    
    public void insertNode(int key, int val) {
        tail.next = new Node(key, null, tail);
        tail = tail.next;
        keyValueMap.put(key, val);
        keyNodeMap.put(key, tail);
    }
    
    public void print() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    
    public int get(int key) {
        if(keyNodeMap.containsKey(key)) {
            int val = keyValueMap.get(key);
            deleteNode(key);
            insertNode(key, val);
            return val;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        int delKey = key;
        if(keyNodeMap.size() == capacity && !keyNodeMap.containsKey(key)) {
            delKey = head.next.val;
        }
        deleteNode(delKey);
        insertNode(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */