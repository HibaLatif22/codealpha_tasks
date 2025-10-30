//   CGPA CALCULATOR
#include <iostream>
#include <cctype>
#include <vector>
#include <iomanip>

using namespace std;
// Represents a single course's information (name, credit hours, grade, etc.)
class Courses{  
private:
    string courseName;
    int creditHrs;
    string grade;
    double gradePoint;
public:
    void setCourse(){ // input course info
        cout<<"Enter the name of course :";
        cin.ignore();
        getline(cin, courseName);
        cout<<"Enter its credit hours :";
        cin>>creditHrs;
        while(true){

          cout<<"Enter Grade (either (A to F) or numeric points :";
          cin>>grade;
          if(isdigit(grade[0])){  // if grade= 0.0-4.0 gradePoint = grade
            gradePoint= stod(grade);  // change type from string to double
             }
          if(isalpha(grade[0])){   // if grade=A-F ,convert it
             gradePoint = convertGradeToPoint(grade);  }
          if(gradePoint!=-1){
             break;
            }
     } }
    double convertGradeToPoint(string g){
        if (g == "A" || g == "A+") {
             return 4.0;}
        else if (g == "A-") {
             return 3.7;  }
        else if (g == "B+") {
             return 3.3; }
        else if (g == "B") {
             return 3.0; }
        else if (g == "B-") {
             return 2.7; }
        else if (g == "C+") {
             return 2.3; }
        else if (g == "C") {
             return 2.0; }
        else if (g == "D") {
             return 1.0; }
        else if (g == "F") {
             return 0.0;  }
        else {
             cout << "\033[31m Invalid grade entered!\033[0m" << endl;
             return -1;  }  // return -1 by default if invalid
}
    double get_gradePoints(){
        return gradePoint;}
    int get_creditHrs(){
        return creditHrs;}

    double get_coursePoints(){
        return (creditHrs * gradePoint);

       }
    void display_courseDetails(){
        cout<<left<<setw(20)<<courseName<<setw(15)<<creditHrs<<setw(10)<<gradePoint<<endl;
       }
    };

class Semester{
    // Holds multiple courses and calculates semester GPA
private:
    vector<Courses> courses;
    double semGradePoints;
    int semCreditHrs;
public:
    void addCourses(int n){
        semCreditHrs=0;
        semGradePoints=0;

       for(int i=1 ;i<=n ;i++){
         cout<<"\033[32m  For COURSE # "<<i<<":\033[0m"<<endl;
         Courses temp;  // temporary object of Courses
         temp.setCourse();
         cout<<endl;
         courses.push_back(temp);  // add temp to courses object. So it store all courses.
         semCreditHrs += temp.get_creditHrs();
         semGradePoints += temp.get_coursePoints();
             }
        }
    int get_semCreditHrs(){
        return semCreditHrs; }
    double get_semGradePoints(){
        return semGradePoints;}
    double get_semGPA(){

        return (semCreditHrs == 0)? 0.0:(semGradePoints / semCreditHrs);
        }
    void display_semDetails(){
       cout<<left<<setw(20)<<"COURSE_NAME"<<setw(15)<<"CREDIT_HRS"<<setw(10)<<"GRADE"<<endl;
       cout<<"------------------------------------------------------------------"<<endl;

      for(int i=0; i<courses.size(); i++){
            courses[i].display_courseDetails();
      }
      cout<<"\033[33mSem_Credit_Hrs: "<<semCreditHrs<<"     Sem_Grade_Points: "<<semGradePoints<<endl;
      cout<<"    Sem GPA = "<<fixed<<setprecision(2)<<get_semGPA()<<endl; // setprecision(2) to limit output upto 2 decimal places
      cout<<"\033[0m"<<endl;
      }
   };

class CGPA_calculator{
// Combines all semesters to calculate overall CGPA
private:
    vector<Semester> sem;
    int overall_CreditHrs;
    double overall_GradePoints;
public:
     void addSemesters(){
        overall_CreditHrs=0;
        overall_GradePoints=0;
        int no_c,no_s;
        cout<<"Enter the number of semesters :";
        cin>>no_s;
        for(int i=1; i<=no_s; i++){
            cout<<"\033[36m-------------------\SEMESTER-"<<i<<"--------------------\033[0m"<<endl;
            cout<<"Enter the number of courses :";
            cin>>no_c;

            Semester temp;
            temp.addCourses(no_c);
            sem.push_back(temp);

            overall_CreditHrs += temp.get_semCreditHrs() ;
            overall_GradePoints +=temp.get_semGradePoints();

            }

       }
     double calculate_CGPA(){

          return (overall_CreditHrs == 0)? 0.0 :(overall_GradePoints / overall_CreditHrs);
     }
     void Display_report(){

         system("cls");
         cout<<"\033[36m================== Progress Report =====================\033[0m"<<endl;
         for(int i=0; i<sem.size() ;i++){
             cout<<"------------------------------------------------------------------"<<endl;
             cout<<"\033[31m                   SEMESTER "<<i+1<<"                              \033[0m"<<endl;
             cout<<"------------------------------------------------------------------"<<endl;
             sem[i].display_semDetails();
         }
         cout<<"\033[32mTotal Credit Hours :"<<overall_CreditHrs<<endl;
         cout<<"Total Grade Points :"<<overall_GradePoints<<endl;

         cout<<"  CGPA = "<<fixed<<calculate_CGPA()<<"\033[0m"<<endl;  }

     };

//===============MAIN FUNCTION================
int main()
{
    cout<<"\033[33m========================================================="<<endl;
    cout<<"                    CGPA CALCULATOR                       "<<endl;
    cout<<"=========================================================\033[0m"<<endl;
    CGPA_calculator stu;
    stu.addSemesters();
    stu.Display_report();
    return 0; }
