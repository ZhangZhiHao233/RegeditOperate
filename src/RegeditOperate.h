#pragma once

#include<iostream>
class CRegeditOperate
{
public:
    CRegeditOperate(void);
    ~CRegeditOperate(void);

    //ѡ�����
    void selectRootKey(int nKey);
    //�����Ӽ�
    bool createSubKey(char* chPath, char* chName);
    //ɾ���Ӽ�
    bool deleteSubKey(char* chPath, char* chName);
    //�����ַ���ֵ��
    bool createKeyValue(char* chPath, char* chKey, char* chValue);
    //����DWORD��ֵ��
    bool createKeyValue(char* chPath, char* chKey, DWORD dwValue);
    //����BINARY��ֵ��
    bool createKeyValue(char* chPath, char* chKey, BYTE btValue[]);
    //ɾ����ֵ��
    bool deleteKeyValue(char* chPath, char* chKey);
    //��ȡDWORD��ֵ
    bool getKeyValue(char* chPath, char* chKey, DWORD& dwValue);
    //��ȡ�ַ���ֵ
    bool getKeyValue(char* chPath, char* chKey, std::string& value);
    //��ȡBINARY��ֵ�����ض���������
    bool getKeyValue(char* chPath, char* chKey, BYTE value[]);
    //��ȡBINARY��ֵ������string����
    bool getKeyValueEx(char* chPath, char* chKey, std::string& value);
    //���ݼ�ֵ��
    bool backupKey(char* chPath, char* fileName);
    //��ԭ��ֵ��
    bool restoreKey(char* chPath,char* fileName, bool isSure);
private:
    HKEY m_hKey;

};

