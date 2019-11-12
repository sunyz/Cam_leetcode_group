//参考其他答案，中间会挂，还在调。。
class LRUCache {
public:
    LRUCache(int capacity) {
        c_ = capacity;
    }
    
    int get(int key) {
        int value;
        if (m_.find(key) != m_.end()) {
            cout << 4 << endl;
            cout << "list:" << l_.front() << *next(l_.begin()) <<  endl;
            auto ii = m_[key];
            cout << *m_[key] << endl;
            value = *(m_[key]);
            cout << 5 << endl;
            l_.erase(m_[key]);
        } else {
            return -1;
        }
        cout << 6 << endl;
        l_.push_front(value);
        m_[key] = l_.begin();
        return value;
    }
    
    void put(int key, int value) {
        cout << 1 << endl;
        if (m_.find(key) != m_.end()) {
            l_.erase(m_[key]);
            m_.erase(key);
        } else {

        }
        cout << 2 << endl;
        l_.push_front(value);
        m_[key] = l_.begin();
        cout << 3 << *m_[key] << endl;
        if (l_.size() >= c_) {
            l_.pop_back();
        }
    }
    unordered_map<int, list<int>::iterator> m_;
    list<int> l_;
    int c_ = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 还是在别人基础上改对了。。
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (hash_.find(key) == hash_.end())
            return -1;
        else {
            int value = *hash_[key];
            ls_.erase(hash_[key]);
            ls_.push_front((value));
            hash_[key] = ls_.begin();
            return value;
        }
    }

    void put(int key, int value) {
        if (hash_.find(key) != hash_.end())
            ls_.erase(hash_[key]);
        else if (ls_.size() >= capacity_) {
            hash_.erase(ls_.back());
            ls_.pop_back();
        }
        ls_.push_front((value));
        hash_[key] = ls_.begin();
    }

private:
    int capacity_;
    list<int> ls_;
    unordered_map<int, list<int>::iterator> hash_;
};


