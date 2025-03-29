
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



  sort(students.begin(), students.end(), [](Students a, Students b) {
        return a.StudentMarks > b.StudentMarks;  
    });

// Display sorted student data with ranks
    cout << "Sorted Student List (by Total Marks - Highest to Lowest):\n";
    cout << "---------------------------------------------------------\n";
    cout << "Rank | ID  | Name   | Marks\n";
    cout << "---------------------------------------------------------\n";


// Print the list of students with their ID, Name, and Marks

int rank = 1;
for(const auto& student : students){
     cout << rank << "    | " << student.ID << "  | " << student.StudentName << "  | " << student.StudentMarks << endl;
        rank++; 
    }


    return 0;

}


