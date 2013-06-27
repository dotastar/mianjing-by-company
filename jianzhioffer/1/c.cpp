#include <cstring>

using namespace std;

class CMyString
{
 public:
  CMyString(char* pData = NULL);
  CMyString(const CMyString& str);
  ~CMyString(void);
  CMyString& operator=(const CMyString& str);
 private:
  char* m_pData;
};
CMyString::CMyString(char* pData)
{
  int len = 0;
  if(pData == NULL){
    len = 0;
  } else {
    len= strlen(pData);
  }
  this->m_pData = new char[len+1];
  strcpy(this->m_pData, pData);
  this->m_pData[len] = '\0';
}
CMyString::CMyString(const CMyString& str)
{
    int len = strlen(str.m_pData);
    this->m_pData = new char[len+1];
    strcpy(this->m_pData, str.m_pData);
    this->m_pData[len] = '\0';
}
CMyString::~CMyString()
{
  delete m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{
  if(this != &str){
    int len = strlen(str.m_pData);
    char* temp = new char[len+1];
    delete[] this->m_pData;
    this->m_pData = temp;
    strcpy(this->m_pData, str.m_pData);
    this->m_pData[len] = '\0';
  }
  return *this;
}

int main() {
  char a[] = "test string1";
  CMyString s1 = a;
  CMyString s2 = s1;
  s2 = s2;
  CMyString s3 = s2 = s1;
}
