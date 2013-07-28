#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <sstream>

using namespace std;

class ConsistentHashRing{
 public:
  ConsistentHashRing(int replica_count):replica_count_(replica_count){
  }

  void AddServer(string server_name){
    for(size_t i = 0; i < replica_count_; ++i){
      stringstream ss;
      ss<<server_name<<i;
      m_[hash_func_(ss.str())] = server_name;
    }
  }
  
  void RemoveServer(string server_name){
    for(size_t i = 0; i < replica_count_; ++i){
      stringstream ss;
      ss<<server_name<<i;
      m_.erase(hash_func_(ss.str()));
    }
  }
  
  string LookupServer(string data){
    if(m_.empty()) return "";
    auto it = m_.upper_bound(hash_func_(data));
    if(it == m_.end()){
      return m_.begin()->second;
    } else {
      return it->second;
    }
  }
  
 private:
  const size_t replica_count_;
  hash<string> hash_func_;
  map<size_t, string> m_;
};

void print(ConsistentHashRing& chr){
  cout<<"======================="<<endl;
  cout<<chr.LookupServer("data1")<<endl;
  cout<<chr.LookupServer("data2")<<endl;
  cout<<chr.LookupServer("data3")<<endl;

}
int main() {
  ConsistentHashRing chr(10);
  chr.AddServer("host1");
  chr.AddServer("host2");
  chr.AddServer("host3");
  print(chr);
  chr.AddServer("host4");
  print(chr);
  chr.RemoveServer("host4");
  print(chr);
  return 0;
}
