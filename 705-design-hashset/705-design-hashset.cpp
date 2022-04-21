class MyHashSet {
public:
   vector<bool> ht;
MyHashSet() {
    ht=vector<bool>(1000001,false);
}
void add(int key) {
    ht[key]=true;
}

void remove(int key) {
    ht[key]=false;
}

bool contains(int key) {
    return ht[key]==true;
}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */