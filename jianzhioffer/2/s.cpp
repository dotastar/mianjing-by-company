#include <iostream>

class Singleton{
  static Singleton *instance_;
  Singleton() {};
  Singleton(Singleton const&);
  void operator=(Singleton const&);
 public:
  static Singleton *getInstance(){
    if(instance_ == NULL){
      //lock
      if(instance_ == NULL){
        instance_ = new Singleton;
      }
      //unlock
    }
    return instance_;
  }
};
Singleton* Singleton::instance_ = NULL;

class S
{
    public:
        static S& getInstance()
        {
            static S    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        S() {};                   // Constructor? (the {} brackets) are needed here.
        // Dont forget to declare these two. You want to make sure they
        // are unaccessable otherwise you may accidently get copies of
        // your singleton appearing.
        S(S const&);              // Don't Implement
        void operator=(S const&); // Don't implement
};

int main() {
  Singleton *a = Singleton::getInstance();
  //Singleton b = *a;
  //Singleton *c = Singleton::getInstance();
  //*c = *a;
  S::getInstance();
}
