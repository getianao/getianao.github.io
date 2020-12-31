#include <iostream>
#include <string.h>
using namespace std;
/*
赋值运算符函数

使用strcat(charptr1,charptr2)进行char字符串的连接时需要考虑连接后的字符串长度是否超过charptr1数组的长度，否则会出现segmentation fault。可以新建一个满足长度要求的新charptr数组。

赋值运算符的实现需要注意以下几点：
①为了保证可以连续赋值，赋值运算符的重载需要本类型的引用。同时，如果不是引用，再次调用一次复制构造函数。
②将传入参数声明为常量引用。引用可以减少一次拷贝构造函数，常量是因为不可以改变传入实例的状态。
③释放已有的内存防止内存泄露。
④判断在传入实例和自身实例相同时的情况，防止误释放了自身内存。
*/
class CMyString
{
public:
    CMyString();
    CMyString(char *pData);
    CMyString(const CMyString &str); //拷贝构造函数
    ~CMyString(void);
    CMyString& operator+(const CMyString &str);  //运算符重载函数定义为成员函数
    CMyString& operator=(const CMyString &str); //运算符重载函数定义为成员函数
    void printStr();

private:
    char *m_pData;
};
CMyString::CMyString()
{
    this->m_pData = NULL;
}
CMyString::CMyString(char *pData)
{
    this->m_pData = pData;
}
CMyString::CMyString(const CMyString &str)
{
    this->m_pData = str.m_pData;
}
CMyString& CMyString::operator+(const CMyString &str)
{
    int length = strlen(this->m_pData) + strlen(str.m_pData) + 1;
    char *newPtr = new char[length];
    strcpy(newPtr, this->m_pData);
    strcat(newPtr, str.m_pData);
    this->m_pData = newPtr;
    return *this;
}
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this == &str) //?
    {
        return *this;
    }
    delete[] m_pData; //释放内存
    //m_pData = NULL;
    m_pData = new char [strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
CMyString::~CMyString(void)
{
    cout << "unconstruction" << endl;
}
void CMyString::printStr()
{
    cout << this->m_pData << endl;
}

int main()
{

    CMyString data1("hello,");
    CMyString data2, data3;
    data2 = data3 = data1;
    data1.printStr();
    data2.printStr();
    data3.printStr();
    data3 = data1 + data2;
    data3.printStr();

    //cin.get();
    return 0;
}