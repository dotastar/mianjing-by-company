#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;
// LRU cache, find O(1), insert O(1), delete O(1)
// find use hash, insert and delete use doubly linked list
struct item {
	string key;
	string value;
	struct item *prev;
	struct item *next;
	item(string k, string v):key(k), value(v), prev(nullptr), next(nullptr) {
	}
};

class cache {
	unordered_map<string, item*> hash;
	item *head;
	item *tail;
	size_t n;
	void move_to_head(item *i){
		if(i == head) {
			return;
		} else {
			i->prev->next = i->next;
		}
		if(i == tail){
			tail = i->prev;
		} else {
			i->next->prev = i->prev;
		}
		i->next = head;
		i->prev = nullptr;
		head->prev = i;
		head = i;
	}
public:
	cache() {
		n = 5;
		hash.reserve(n);
		head = nullptr;
		tail = nullptr;

	}

	size_t printn(){
	 return n;
	}
string get(const string key) {
	if (hash.find(key) == hash.end())
		return "";
	string value;
	item* i = hash[key];
	move_to_head(i);
	return i->value;
}

bool put(const string key, const string value) {
	if (hash.find(key) != hash.end()){
		item* i = hash[key];
		move_to_head(i);
		i->value = value;
	} else {
		if(hash.size() >= n){
			hash.erase(tail->key);
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		item *i = new item(key, value);
		if(head == nullptr) {
			head = i; 
			tail = i;
		} else {
			i->next = head;
			head->prev = i;
			head = i;
		}
		pair<string, item*> new_pair(key, i);
		hash.insert(new_pair);
	}	
	return true;
}
};

int main() {
	cache c;
	assert(c.get("wuyang") == "");
	c.put("wuyang", "baba");
	assert(c.get("wuyang") == "baba");
	c.put("yangyang", "mama");
	assert(c.get("yangyang") == "mama");
	c.put("dingding1", "baobao1");
	c.put("dingding2", "baobao2");
	c.put("dingding3", "baobao3");
	c.put("dingding4", "baobao4");
	assert(c.get("wuyang") == "");

	return 0;
}
