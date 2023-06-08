/*
705. Design HashSet
Easy
3.4K
274
company
Microsoft
company
Apple
company
Amazon

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.
    bool contains(key) Returns whether the value key exists in the HashSet or not.
    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

 

Constraints:

    0 <= key <= 106
    At most 104 calls will be made to add, remove, and contains.

Accepted
345.1K
Submissions
511.8K
Acceptance Rate
67.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (38)
Similar Questions
Design HashMap
Easy
Design Skiplist
Hard
Related Topics
Array
Hash Table
Linked List
Design
Hash Function
*/
class MyHashSet {
public:
    const int p = 2381;
    vector<list<int>> hash_table;

    MyHashSet() {
        hash_table.resize(p);
    }
    
    void add(int key) {
        int ind = key % p;

        for(int& v : hash_table[ind])
            if(v == key)
                return ;

        hash_table[ind].emplace_back(key);
    }
    
    void remove(int key) {
        int ind = key % p;

        for(auto it = hash_table[ind].begin(); it != hash_table[ind].end(); it++)
            if(*it == key)
            {
                hash_table[ind].erase(it);
                return;
            }
    }
    
    bool contains(int key) {
        int ind = key % p;
        
        for(int& v : hash_table[ind])
            if(v == key)
                return 1;

        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */