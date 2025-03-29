
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Define a struct to store student details (ID, Name, Marks)
struct Students{
    int ID;
    string StudentName;
    int StudentMarks;
    
   
    
};

int main()
{
// use vector to add dynamic students data in to the struct
   vector<Students> students;
    
 students.push_back({144, "Hammad", 95});
    students.push_back({7, "Ahsan", 85});
    students.push_back({64, "Hamza", 91});
    students.push_back({44, "Zubair", 87});
    students.push_back({1, "Zakir", 88});
    students.push_back({17, "Asher", 76});

// Sort the student data in ascending order by student ID using a lambda function.
// Sorting is based on ID.

sort(students.begin(), students.end(), [](Students a, Students b) {
    return a.ID < b.ID;
});

// Print the list of students with their ID, Name, and Marks
cout<<"List Data"<<endl;
for(const auto& student : students){
     cout << student.ID << " " << student.StudentName << " " << student.StudentMarks << endl;

}

cout<<"================"<<endl;

cout <<"Search Item"<<endl;

// Initialize variables for binary search (searchID, LOW, HIGH, found flag)



int searchID = 7; 
int LOW = 0;
int HIGH = students.size()-1; 
// bool found = false;

// Implement binary search to efficiently find a student by mid

while(LOW <= HIGH){
  int mid = (LOW + HIGH) / 2;
  
//   Display student details if the ID is found
  
  if(  students[mid].ID == searchID){
        cout << students[mid].ID << " " << students[mid].StudentName << " " << students[mid].StudentMarks << endl;
        // found =  true;
        break;
  }
 if (students[mid].ID > searchID) {
    HIGH = mid - 1;  
} else {
    LOW = mid + 1;   
}

 
}
if(LOW > HIGH) {
    cout << "ID not found" << endl;
}



    return 0;
}



