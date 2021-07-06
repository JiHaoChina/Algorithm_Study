# LRU算法

题目要求如下：

实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

### 可以根据题目，总结出大致思路：

LRU的全写是Least Recently Used 最近最少使用。
LRU是缓存淘汰机制的一种。 缓存的淘汰机制有三种：队列，LRU 和LFU。
LRU的淘汰机制，效果像队列一样。最新插入和最新访问的要放在最前面。

访问的时候， 如果遍历到了key，就需要把key对应的节点，从原来的位置删除，更新到最新访问位置。
在插入数据的时候，先判断缓存中是否已存在，相同的索引(关键字)，如果存在，更新对应的值，并更新为最新访问的数据节点。
在插入新数据的时候，需要判断容量是否达到上限。 当容量达到上限的时候，删除最久未使用的数据节点，然后再插入并更新为最新访问的数据节点。




```c++
class LRUCache {
public:
    class Node
    {
        public:
            int key;
            int val;
            Node* pre;
            Node* next;
            Node(){}
            Node(int mkey, int mvalue):key(mkey),val(mvalue),pre(NULL),next(NULL)
            { }
    };
    //构造函数
    LRUCache(int capacity) {
        this->size = capacity;

        //头尾保护节点
        head = new Node();
        tail = new Node();
        //初始化双链表关系
        head->next = tail;
        tail->pre = head;
    }

    Node* delete_currentnode(Node* current)
    {
        current->pre->next = current->next;
        current->next->pre = current->pre;
        return current;
    }

    //相当于在链表中一个insert操作，在head 和 head的next之间插入一个节点
    void move_to_head(Node* current)
    {
        Node* next = head->next;

        head->next = current;
        current->pre = head;

        next->pre = current;
        current->next = next;
    }

    void make_recently(Node* current)
    {
        Node* temp =delete_currentnode(current);

        //不能直接 使用current, 因为这样会更改 current 的原来的前后的对应的值，因此 用一个中间值？
        move_to_head(temp);
    }

    int get(int key) {
        int ret = -1;
        //get 到key的value,要进行将key的对值从存储结构中删除，然后重新排列前后的数据
        if(map.find(key)!= map.end())
        {
            Node* temp = map[key];
            make_recently(temp);
            ret = temp->val;
        }
        return ret;
    }
    //关键字存在，变更其数值
    //关键字不存在的时候，再插入。 插入时，先判断是否达到容量上限
    void put(int key, int value) {
        if(map.find(key) != map.end())
        {
            Node* temp = map[key];
            temp->val = value;
            make_recently(temp);
        }
        else
        {
            if(map.size() == size)
            {
                //删除尾部，最久未使用的节点
                Node* temp = delete_currentnode(tail->pre);
                map.erase(temp->key);
            }
            //插入新节点
            Node* temp = new Node(key,value);
            move_to_head(temp);
            //插入新节点后，要记录至哈希表中
            map[key] = temp;
        }
    }

public:
    //类内共享容量值
    int size;

    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
};
```

