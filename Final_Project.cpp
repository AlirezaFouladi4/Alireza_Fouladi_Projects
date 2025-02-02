#include <iostream>
#include<string>

using namespace std;

struct course {
string name ;
float mark ;
int units ;
};
struct stud {
string name ;
string id ;
string major ;
float avg =0  ;
 course courses [10] ;
 int  coursecount = 0 ;
};
stud students [50] ;
 int studentcount = 0 ;

 void addstude() {
 stud s ;
 cout << "\n ** adding student ** \n " ;
 cout << " name :  " ;
 cin.ignore() ;
 getline(cin , s.name) ;
 cout << "ID :  " ;
 cin >> s.id ;
 cout <<  "major :  "  ;
 cin >> s.major ;
students [studentcount] = s ;
 studentcount ++ ;
 }
void addcource () {
string id ;
cout << "ID  :  " ;
cin >> id ;
bool found = false ;
for ( int i=0 ; i<studentcount ; i++) {
    if (students[i].id == id )  {
        found = true ;
        cout << "course name  :  "  ;
        cin >> students[i].courses[students[i].coursecount].name ;
                 cout << "course units   :  "  ;
        cin >> students[i].courses[students[i].coursecount].units ;
                cout << "course mark   :  "  ;
        cin >> students[i].courses[students[i].coursecount].mark ;
        students[i].coursecount ++ ;


        float sum = 0 ;
        int totalunits = 0 ;
        for ( int j =0 ; j<students[i].coursecount ; j++)
        {
            sum +=students[i].courses[j].units * students[i].courses[j].mark ;
            totalunits += students[i].courses[j].units ;
        }
        students[i] . avg = totalunits > 0 ?  sum / totalunits : 0 ;
        cout << "  done ,  student added   " << endl ;
        break ;
        }
    }
if(!found)
    cout << " there is no student with the  given information " ;
}

void displaystudents(string filter = " ")  {

    for(int i=0 ; i<studentcount-1 ; i++) {
      for(int j=i+1 ; j<studentcount ; j++) {

        if (students[i].avg<students[j].avg) {
            stud temp = students[i] ;
            students[i] = students[j] ;
            students[j] = temp ;
        }

    }

    }

    for ( int i = 0 ; i < studentcount ; i++ )
    {
        if (filter != " " && students[i].major != filter)
            continue ;

        stud s  = students[i] ;
        cout << endl ;
        cout << "name  :  " << s.name << endl ;
        cout << " ID   :  " << s.id << endl ;
        cout << " major  :  " << s.major << endl ;
        cout << " avg    :  " << s.avg << endl ;
        cout << "---------------------------------" << endl ;

    }

}

 void displayreport () {
 string id ;
 cout << "  ID   :  "  ;
 cin >> id ;


  for ( int i = 0 ; i<studentcount ; i++)
  {
       if ( students[i].id == id ) {
  cout << ".................................................." ;
        cout<<endl << "\n *** REPORT ***" << endl ;

        cout <<endl<< "name  :  " << students[i].name << endl  ;
          cout << " ID  :  " << students[i].id << endl  ;
            cout << " major   :  " << students[i].major << endl  ;
              cout << " avg   :  " << students[i].avg << endl  ;


        cout <<endl<<endl<< " *** COURSES ***  " << endl ;

        for ( int j = 0 ; j < students[i].coursecount ; j++  )
        {
            cout <<endl<< students[i].courses[j].name << " | " << " untis :  "<< students[i].courses[j].units << " | " <<" mark   :  "<< students[i].courses[j].mark << endl;
            cout<<endl<<".................................................." ;
        }
        return ;
       }
  }
 cout <<  " there is no student with the given information"  << endl ;
 }

int main()
{
while ( true)
{
    cout << "      {    wellcome    }    " << endl<<endl ;
    cout <<  "main menu  :  "  << endl ;
    cout << " 1 . add student " << endl ;
    cout << " 2 . add course " << endl ;
    cout << " 3 . display students list " << endl ;
    cout << " 4 . display report card " << endl ;
    cout << " 5 . exit " << endl ;
    cout << "    your choice :  "  << endl ;

    int ch ;
    cin >> ch ;
    if (ch==1)
        addstude() ;
    else if (ch==2)
    addcource() ;
     else if (ch==3)
     {
         cout << " 1 . all students " << endl ;
         cout << " 2 . filter by major " << endl ;
         cout << " your choice :  " << endl;
         cin >> ch ;
         if ( ch == 2 ) {
            string major ;
            cout << " major  : " ;
            cin >> major ;
            displaystudents(major) ;

         }
         else {
            displaystudents() ;
         }

     }
     else if (ch==4)
     displayreport() ;
     else if (ch==5)
        break ;
     else cout << " invalid choice" << endl ;

}
    return 0;
}
