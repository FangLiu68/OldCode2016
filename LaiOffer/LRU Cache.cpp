#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
int main(){
    string s0;
    string s1 = "how are you";
    cout << s0 << endl;
    cout << s1 << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(s0) << endl;
    cout << sizeof(s1) << endl;
    cout << endl << endl;
    char c1[] = "offer";
    cout << strlen(c1) << endl;
    cout << sizeof(c1) << endl;
    cout << endl << endl;
    c1[1] = '\0';
    cout << strlen(c1) << endl;
    cout << sizeof(c1) << endl;
    cout << endl << endl;
    char c2[] = "xyz";
    *(c2+1) = 'x';
    *(c2+2) = 'x';
    *(c2+3) = 'x';
    cout << strlen(c2) << endl;
    cout << c2 << endl;
    cout << sizeof(c2) << endl;
    cout << endl << "===========" << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(string) << endl;
    string s3 = "this is a test";
    cout << "sizeof s3 is " << sizeof(s3) << endl;
    return 0;
}*/


/*
 Main Idea:
 Case 1: cache miss: put the new data in the front of the queue. evicted the end of the queue.
 Case 2: cache hit: put this data hit in the front of the queue.
 E.g.,  each data cached is a URL

 Cache content (in doubled linked list):
 url7<-->  Url8 <->Url2< ->  Url3…. <->  Url7<-->Url 9….
 head		 	prev	       curr	    next



 Hash_table <key = url,     value =  pointer to the element in the double linked list>
 www.cnn.com                 & url7


 */
/*
template <class T>
class LRU {
private:
    map<string, T*> table;  // hashtable
    int size;	 // the current number of elements in the cache
    const int MAX_CAPACITY;   // the total size of the cache
public:
    void Insert(T* t)  {
        if(size >= MAX_CAPACITY)
            Remove();
        if(table.count(T->name) == 0) {  // check whether cache missed or not
            T* nNode = new T(t);
            table[t.name] = nNode;  // <name, address> is inserted into hash_table
            nNode->next = head;
            if(head)
                head->prev = nNode;
            head = nNode;
            if(size == 0) {
                tail = nNode;
                tail->prev = NULL;
                tail->next = NULL;
            }
        }
        size++;
        return;
    }

    T* Get(string& s)  {
        if(table.count(s) == 0) {
            return NULL;
        } else {
            if(table[s] != head) {
                T* Prev = table[s]->prev;
                T* Next = table[s]->next;
                table[s]->next = head;
                head->prev = table[s];
                head = table[s];
                if(Prev)
                    Prev->next = Next;
                if(Next)
                    Next->prev = Prev;
            }
            return(table[s]);
        }
    }

    void Remove() {
        // remove the last element in the linkedlist when inserting a new element
        if(tail) {
            tail = tail->prev;
            delete tail->next;
            if(tail->next)
                tail->next = NULL;
            size--;
            if(size == 0)
                head = NULL;
        }
    }
};
*/



/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/*
 LRU Cache
 Design and implement a data structure for Least Recently Used(LRU) cache. It should support the following operations:
 get and set.
 get(key) - get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate teh least recently used item before inserting a new item.

 为了使查找、插入和删除都有较高的性能,我们使用一个双向链表 (std::list) 和一个哈希表 (std::unordered_map),因为:
 • 哈希表保存每个节点的地址,可以基本保证在O(1)时间内查找节点
 • 双向链表插入和删除效率高,单向链表插入和删除时,还要查找节点的前驱节点
 具体实现细节:
 • 越靠近链表头部,表示节点上次访问距离现在时间最短,尾部的节点表示最近访问最少
 • 访问节点时,如果节点存在,把该节点交换到链表头部,同时更新hash表中该节点的地址
 • 插入节点时,如果cache的size达到了上限capacity,则删除尾部节点,同时要在hash表中删 除对应的项;新节点插入链表头部
 */

class LRUCache{
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v):key(k),value(v){}
    };
    list<CacheNode> cacheList;

    //
    unordered_map<int, list<CacheNode>::iterator> hashTable;

    int capacity;
    void MoveToHead(int _key){
        // move key from current location to head
        list<CacheNode>::iterator updateEntry = hashTable[_key];
        cacheList.erase(updateEntry);
        cacheList.push_front(*updateEntry);
        hashTable[_key] = cacheList.begin();
    }
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get1(int key){
        if(hashTable.find(key) == hashTable.end())
            return -1;
        // 把当前访问的节点移到链表头部，并且更新map中该节点的地址
        cacheList.splice(cacheList.begin(), cacheList, hashTable[key]);
        hashTable[key] = cacheList.begin();
        return hashTable[key]->value;
    }

    void set1(int key, int value){
        if(hashTable.find(key) == hashTable.end()){
            // 删除链表尾部节点（最少访问节点）
            if(cacheList.size() == capacity){
                hashTable.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // 插入新节点到链表头部，并且在map中增加该节点
            cacheList.push_front(CacheNode(key, value));
            hashTable[key] = cacheList.begin();
        }
        // 更新节点的值，把当前访问的节点移到链表头部，并且更新Map中该节点的地址
        else{
            hashTable[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, hashTable[key]);
            hashTable[key] = cacheList.begin();
        }
    }

    int get(int _key){
        if(hashTable.find(_key) == hashTable.end()) return -1; // _key is not in the map

        // if find _key, move the key-value pair to the beginning of the list
        // transfer element pointed by cacheMap[_key] from cacheList into the container, then insert it at position begin()
        //cacheList.splice(cacheList.begin(), cacheList, cacheMap[_key]);
        //cacheMap[_key] = cacheList.begin(); // update the address in map

        MoveToHead(_key);
        return hashTable[_key]->value;
    }

    void set(int _key, int _value){
        if(hashTable.find(_key) == hashTable.end()){
            CacheNode newItem(_key, _value);
            if(cacheList.size() >= capacity){
                // remove from tail
                hashTable.erase(cacheList.back().key);
                cacheList.pop_back();
            }

            // insert in head
            cacheList.push_front(newItem);
            hashTable[_key] = cacheList.begin();
            return ;
        }
        hashTable[_key]->value = _value;
        MoveToHead(_key);
    }

};

class LRUCache1{
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v):key(k),value(v){}
    };
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
    void MoveToHead(int _key){
        // move key from current location to head
        list<CacheNode>::iterator updateEntry = cacheMap[_key];
        cacheList.erase(cacheMap[_key]);
        cacheList.push_front(*updateEntry);
        cacheMap[_key] = cacheList.begin();
    }
public:
    LRUCache1(int capacity){
        this->capacity = capacity;
    }

    int get(int _key){
        if(cacheMap.find(_key) == cacheMap.end()) return -1; // _key is not in the map
        MoveToHead(_key);
        return cacheMap[_key]->value;
    }

    void set(int _key, int _value){
        if(cacheMap.find(_key) == cacheMap.end()){
            CacheNode newItem(_key, _value);
            if(cacheList.size() >= capacity){ // remove from tail
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // insert in head
            cacheList.push_front(newItem);
            cacheMap[_key] = cacheList.begin();
        }
        else{
            cacheMap[_key]->value = _value;
            MoveToHead(_key);
        }
    }
    
};


