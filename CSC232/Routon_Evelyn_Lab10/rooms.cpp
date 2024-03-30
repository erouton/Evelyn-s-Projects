#include <iostream>
#include <map>
using namespace std;

class Room{
    private:
        string name;
        int number;
        string instructor;
        string time;
    public:
        Room(){
            name = " ";
            number = 0;
            instructor = " ";
            time = " ";}
        Room(string na, int n, string i, string t){
            name = na;
            number = n;
            instructor = i;
            time = t;}
        void setName(string na){name = na;}
        void setNumber(int n){number = n;}
        void setInstructor(string i){instructor = i;}
        void setTime(string t){time = t;}
        string getName()const{return name;}
        int getNumber()const{return number;}
        string getInstructor()const{return instructor;}
        string getTime()const{return time;}
};

int main(){
    string searchName;

    Room room1("CS101", 3004, "Haynes", "8:00am");
    Room room2("CS102", 4501, "Alvarado", "9:00am");
    Room room3("CS103", 6755, "Rich", "10:00am");
    Room room4("NT110", 1244, "Burke", "11:00am");
    Room room5("CM241", 1411, "Lee", "1:00pm");

    map<string, Room> course;
    map<string, Room>::iterator iter;

    course[room1.getName()] = room1;
    course[room2.getName()] = room2;
    course[room3.getName()] = room3;
    course[room4.getName()] = room4;
    course[room5.getName()] = room5;

    cout << "Enter a course number to get information about that course: ";
    getline(cin, searchName);
    iter = course.find(searchName);

    if(iter != course.end()){
        cout << "Room Number: " << iter->second.getNumber() << endl;
        cout << "Instructor: " << iter->second.getInstructor() << endl;
        cout << "Meeting Time: " << iter ->second.getTime() << endl;
    }else{
        cout << "Course not found.\n";
    }
    return 0;
}
