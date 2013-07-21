#include <iostream>

using namespace std;

class TCPState;
class TCPStateClosed;
class TCPStream;
class TCPConnection;


class TCPState{
 public:
  virtual void Connect(TCPConnection* c){};
  virtual void Listen(TCPConnection* c){};
  virtual void Close(TCPConnection* c){};
  virtual void Send(TCPConnection* c){};
  virtual void SYN(TCPConnection* c){};
  virtual void ACK(TCPConnection* c){};
    virtual void RST(TCPConnection* c){};
  virtual void FIN(TCPConnection* c){};

 protected:
  void ChangeState(TCPConnection* c, TCPState *s){
    c->ChangeState(s);
  }
};
class TCPStateClosed: public TCPState{
 public:
  static TCPState *Instance(){
    if(instance_ == nullptr){
      instance_ = new TCPStateClosed;
    }
    return instance_;
  }
 protected:
  TCPStateClosed();
 private:
  static TCPStateClosed *instance_;
};
TCPStateClosed *TCPStateClosed::instance_ = nullptr;

class TCPStateListen:public TCPState{
};
class TCPStateSynRcvd:public TCPState{
};
class TCPStateSynSent:public TCPState{
};
class TCPStateEstablished:public TCPState{
};
class TCPStateFinWait1:public TCPState{
};
class TCPStateFinWait2:public TCPState{
};
class TCPStateTimedWait:public TCPState{
};
class TCPStateClosing:public TCPState{
};
class TCPStateCloseWait:public TCPState{
};
class TCPStateLastAck:public TCPState{
};

class TCPConnection{
  friend class TCPState;
 public:
  TCPConnection(){
    state_ = TCPStateClosed::Instance();
  }
  void Connect(){
    state_->Connect(this);
  }
  void Listen(){
    state_->Listen(this);
  }
  void Close(){
    state_->Close(this);
  }
  void Send(){
    state_->Send(this);
  }
  void SYN(){
    state_->SYN(this);
  }
  void ACK(){
    state_->ACK(this);
  }
  void RST(){
    state_->RST(this);
  }
  void FIN(){
    state_->FIN(this);
  }
  void ProcessStream(TCPStream * s){
  }
 private:
  void ChangeState(TCPState *s){
    state_ = s;
  }

  TCPState *state_;
};

int main(){
  return 0;
}
