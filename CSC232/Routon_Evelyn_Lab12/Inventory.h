#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
using namespace std;

class Inventory{
private:
    int serialNum;
    string manufactDate;
    int lotNum;   
public:
    Inventory(){
        serialNum = 0;
        lotNum = 0;
        manufactDate = " ";  }

    Inventory(int s, string m, int l){
        serialNum = s;
        manufactDate = m;
        lotNum = l;  }
        
    int getserialNum(){  return serialNum; }
    string getmanufactDate(){  return manufactDate; }
    int getlotNum(){   return lotNum; }
    void setserialNum(int num){  serialNum = num; }
    void setmanufactDate(string date){  manufactDate = date; }
    void setlotNum(int num){  lotNum = num; }
    friend ostream& operator<<(ostream& os, const Inventory& item){
        os << "Serial Number: " << item.serialNum
            << endl;
        return os;
    }
};

#endif