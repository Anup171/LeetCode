class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if(cache.size()>capacity){
            Node* del=head->next;
            remove(del);
            cache.erase(del->key);
            delete del;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */