class LRUCache {
public:
    class Node
    {
        public:
        Node() {}
        Node(int key,int value):key(key),val(value),pre(NULL),next(NULL){}

        int key;
        int val;
        Node* pre;
        Node* next;

    };
	
    LRUCache(int capacity) {
        this->size = capacity;
        //设立头尾保护节点
        head = new Node();
        tail = new Node();
        //初始化双链表关系
        head->next = tail;
        tail->pre = head;

    }
	//将访问节点，从原链表中删除
    Node* delete_origin(Node* current)
    {
        Node* next = current->next;

        current->pre->next = next;
        current->next->pre = current->pre;
        
        return current;
    }

    //在head 和 head->next之间插入节点， 为最新访问的
    void insert_head(Node* current)
    {
        Node* temp = head->next;

        current->pre = head;
        head->next = current;
        current->next = temp;
        temp->pre = current;
    }
	//更新为最新访问数据 ，需要从原链表中删除，再在头部插入
    void make_first(Node* current)
    {
        Node* temp = delete_origin(current);
        insert_head(temp);
    }
    
    //关键字存在缓存中，返回关键字的值
    //查询到，就要更改为最新访问的值，1.从原位置删除 2.将数据插入到头
    int get(int key) {
        int ret = -1;
        if( map.find(key)!= map.end() )
        {
            Node* temp = map[key];
            make_first(temp);
            return temp->val;
        }
        return ret;
    }
    
    //关键字存在，更新值,并且最新访问； 关键字不存在，插入
    void put(int key, int value) {
        //关键字存在
        if(map.find(key)!= map.end() )
        {
            Node* temp = map[key];
            temp->val = value;
            make_first(temp);
        }
        else
        {
            //关键字不存在，需要插入新数值对，再考虑缓存是否达上限（插入的时候才需考虑是否达容量）
            if(map.size() == size)
            {
                Node* temp = delete_origin(tail->pre);
                map.erase(temp->key);
            }
            Node* temp = new Node(key,value);
            insert_head(temp);
            map[key] = temp;
        }
        
    }

public:
    int size;

    unordered_map<int , Node*> map;
    Node* head = NULL;
    Node* tail = NULL;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */