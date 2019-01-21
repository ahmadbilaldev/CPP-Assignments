    #include<iostream>
    #include<iomanip>
    #include<string>
    #include<fstream>
    using namespace std;

    

    // CRUD -- Create Read Update Delete functions.
    
    // Course related Functions.
    void AddCourse( string code[], int creditHrs[], int semester [], string name[], string cCode, string cName, int crdHrs, int cSemester );
    void EditCourse( string code[], int creditHrs[], int semester[], string name[], string cCode, string cName, int crdHrs, int cSemester );
    void DeleteCourse( string code[], int creditHrs[], int semester[], string name[] );
    void ViewCourses( string code[], int creditHrs[], int semester[], string name[] );
    void ViewSemesterCourses( string code[], int creditHrs[], int semester[], string name[], int semesterCourses );
    void CourseDetails( string code[], int creditHrs[], int semester[], string name[], int counter, string currCode, int creditH, int currSemester, string currName );
    bool storeCourses( string code[], int creditHrs[], int semester[], string name[] );
    bool loadCourses( string code[], int creditHrs[], int semester[], string name[] );

    // Student related Functions.
    void AddStudent( string stdNamesList[], string stdRegNoList[], string studentName, string regNo );
    void UpdateStudent ( string stdNamesList[], string stdRegNoList[], string studentName, string regNo );
    void DeleteStudent ( string stdNamesList[], string stdRegNoList[], string studentName, string regNo );
    void ViewStudents ( string stdNamesList[], string stdRegNoList[], string stdCoursesList[100][100] );
    void updateStudentDetails( int index, string stdNamesList[], string stdRegNoList[], string studentName, string regNo );
    void RegisterCourse( string stdRegNoList[], string stdCoursesList[100][100], string courseCode[], string regNo, string cCode );
    void unRegisterCourse( string stdRegNoList[], string stdCoursesList[100][100], string regNo, string cCode );

    // LogIn Functions.
    bool loadUsers( string usersList[], string passwordsList[] );
    bool loginAuth( string usersList[], string passwordsList[], string loginUser, string loginPass );
    
    // Counter and Index finder Functions.
    int  findCounter( int semester[] );
    int  findIndex( string code[], string currCode, int semester [] );
    int  findStdIndex( string stdRegNoList[], string regNo );
    int  findStdCourseIndex( string stdCoursesList[100][100], string cCode, string stdRegNoList[], string regNo );
    int  findStdCourseCounter( string stdCoursesList[100][100], int stdIndex );

    // Validators.
    bool isValidCourseCode( string code );
    bool isValidCourseName( string name );
    bool isValidStudentName( string stdName );
    bool isValidCourse( string currCode, int creditH, int currSemester, string currName );
    bool isValidRegNumber( string regNo );
    bool isValidCreditHours( int );
    bool isValidSemester( int );
    bool isValidDig( char validDig );
    bool isValidCh( char validCh );

    int counterUsers = 0; // Counter for number of users.

    int main() {

        string courseCode[100], courseName[100], usersList[100], passwordsList[100], stdNamesList[100], stdRegNoList[100]="0";
        string cName, cCode, regNo, stdName, loginUser, loginPass;
        int semester[100]={0}, creditHrs[100], semesterCourses, option, crdHrs=0, cSemester=0;
        bool login = false, relogin = false, validInput, programExit = false;
        string stdCoursesList[100][100];
        // Initialize all components of the 2-D array to "0" for counter, so that we may find number of courses already added.
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                stdCoursesList[i][j] = "0";
            }
        }
        cout << "|******************************************************|" << endl;
        cout << "|******************************************************|" << endl;
        cout << "|** Welcome to University Learning Management System **|" << endl;
        cout << "|******************************************************|" << endl;
        cout << "|******************************************************|" << endl;

        // Authentication. 
        
       if( !loadUsers ( usersList, passwordsList ) ) {      // loads user login info from file.
           cout << "Error. Sorry we are unable to run the program as user information is not found.";
           return 1;
       }

       if (! loadCourses( courseCode, creditHrs, semester, courseName ) ) { // Loads courses from file.
            cout << "No pre-loaded courses found." << endl << endl;
       }

        while ( !login ) {     // Keep asking for user and password until login is successfull.
                
            cout << "\nThis system is meant to be used by authorized users only." << endl;
            cout << "Login to the system to get access" << endl;
            cout << "Username: ";
            cin  >> loginUser;
            cout << "Password: ";
            cin  >> loginPass;

                if( loginAuth( usersList, passwordsList, loginUser, loginPass ) ) {
                    cout << endl << "Logged in successfully.";
                    login = true; 
                }
                else {
                    cout << endl << "Login Failed. Try again." << endl;
                }
        }

        while( !programExit ) {
            cout << "\n" << "--------------------------" << endl << "Following are the options: " << endl << "--------------------------" << endl;
            cout << "1." << "\t" << "Add Course." << endl;
            cout << "2." << "\t" << "Update Course." << endl;
            cout << "3." << "\t" << "Delete Course." << endl;
            cout << "4." << "\t" << "View all Courses." << endl;
            cout << "5." << "\t" << "View Courses of a semester." << endl;
            cout << "6." << "\t" << "Add New Student." << endl;
            cout << "7." << "\t" << "Update Student." << endl;
            cout << "8." << "\t" << "Delete Student." << endl;
            cout << "9." << "\t" << "View All Students." << endl;
            cout << "10." << "\t" << "Register the course for student." << endl;
            cout << "11." << "\t" << "Un-Register the course for student." << endl;
            cout << "12." << "\t" << "Logout of the system." << endl;
            cout << "13." << "\t" << "Exit Program." << endl << endl;

            cout << "Choose an option: " << endl; 
            cin  >> option;

            if ( option > 0 && option < 14 ) {
                    validInput=true;
                }
            else {
                    validInput=false;
            }
            
            if ( cin.fail() ) {
                option=6;
                validInput=true;
                cout << "Error. You can only input options from 1 to 6. Program will exit now." << endl;
            }
            else {

                while( !validInput ) {
                    cout << "Invalid input. Option does not exist. Try again." << endl;
                    cout << "Choose an option: " << endl; 
                    cin  >> option;
                    if ( option > 0 && option < 8 ) {
                        validInput=true;
                    }
                    else {
                        validInput=false;
                    }
                }
            }
            if ( validInput ) {

                switch( option ) {

                    case 1:
                        AddCourse( courseCode, creditHrs, semester, courseName, cCode, cName, crdHrs, cSemester );
                        break;
                    case 2:
                        EditCourse( courseCode, creditHrs, semester, courseName, cCode, cName, crdHrs, cSemester );
                        break;
                    case 3:
                        DeleteCourse( courseCode, creditHrs, semester, courseName );
                        break;
                    case 4:
                        ViewCourses( courseCode, creditHrs, semester, courseName );     // View all added courses.
                        break;
                    case 5:
                        cout << "Enter the semester: ";     // View the courses of only a given semester.
                        cin  >> semesterCourses;
                
                        if( isValidSemester( semesterCourses ) ) {
                            ViewSemesterCourses( courseCode, creditHrs, semester, courseName, semesterCourses );
                        }
                        else {
                            cout << "Invalid input." << endl;
                        }
                        break;
                    
                    case 6:
                        cout << "Enter details of the student." << endl;
                        cout << "Enter Registration number followed by name of student: ";
                        cin  >> regNo;
                        cin.ignore();
                        getline( cin, stdName);

                        if ( !isValidRegNumber(regNo) ) {           // Reg. number check.
                            cout << "The registration number you added is not valid." << endl;
                            break;
                        }
                        if ( !isValidStudentName(stdName) ) {       // Name check.
                            cout << "The student name you added is not valid." << endl;
                            break;
                        }
                        AddStudent ( stdNamesList, stdRegNoList, stdName, regNo );
                        cout << endl << "The New Student has been added successfully.";
                        break;

                    case 7:
                        cout << "Enter Registration Number of the student you want to edit: ";
                        cin  >> regNo;

                        if ( !isValidRegNumber(regNo) ) {           // Reg. number check.
                            cout << "The registration number you added is not valid." << endl;
                            break;
                        }
                        if ( findStdIndex(stdRegNoList, regNo) == -1 ) {
                            cout << "The student does not exist. Try adding first.";
                            break;
                        }
                        else {
                            UpdateStudent( stdNamesList, stdRegNoList, stdName, regNo );
                            cout << endl << "The student has been edited successfully.";
                            break;
                        }

                    case 8:
                        cout << "Enter the registration number of the student you want to delete:" << endl;
                        cin  >> regNo;
                        if ( !isValidRegNumber(regNo) ) {           // Reg. number check.
                            cout << "The registration number you added is not valid." << endl;
                            break;
                        }
                        if ( findStdIndex(stdRegNoList, regNo) == -1 ) {
                            cout << "The student does not exist.";
                            break;
                        }
                        else {
                            DeleteStudent( stdNamesList, stdRegNoList, stdName, regNo );
                            cout << "The student as been deleted successfully" << endl;
                            break;
                        }
                    
                    case 9:
                        ViewStudents ( stdNamesList, stdRegNoList, stdCoursesList );
                        break;

                    case 10:
                        cout << "Course Registration:" << endl;
                        cout << "For registration of courses, enter the registration number of student:" << endl;
                        cin  >> regNo;
                        // Checks
                        if ( !isValidRegNumber(regNo) ) {
                            cout << "Invalid registraion number.";
                            break;
                        }
                        if ( findStdIndex(stdRegNoList, regNo) == -1 ) {
                            cout << "The specified student does not exist.";
                            break;
                        }
                        cout << "To register any course, enter its course code: ";
                        cin  >> cCode;
                        if( !isValidCourseCode(cCode) ) {
                            cout << "The course code you entered is not valid";
                            break;
                        }
                        if ( findIndex( courseCode, cCode, semester ) == -1 ) {
                            cout << "No existing course has the specified course code.";
                            break;
                        }

                        RegisterCourse( stdRegNoList, stdCoursesList, courseCode, regNo, cCode );
                        cout << "The course has been registered successfully.";
                        break;
                    
                    case 11:
                        cout << "Course Un-registration" << endl;
                        cout << "For un-registration of course, enter the registration number of student:" << endl;
                        cin  >> regNo;
                        // Checks.
                        if ( !isValidRegNumber(regNo) ) {
                            cout << "Invalid registraion number.";
                            break;
                        }
                        if ( findStdIndex(stdRegNoList, regNo) == -1 ) {
                            cout << "The specified student does not exist.";
                            break;
                        }
                        cout << "To register any course, enter its course code: ";
                        cin  >> cCode;
                        if( !isValidCourseCode(cCode) ) {
                            cout << "The course code you entered is not valid";
                            break;
                        }
                        if ( findIndex( courseCode, cCode, semester ) == -1 ) {
                            cout << "No existing course has the specified course code.";
                            break;
                        }
                        if( findStdCourseIndex(stdCoursesList, cCode, stdRegNoList, regNo) ==-1 ) {
                            cout << "The course is already not registered.";
                            break;
                        }

                        unRegisterCourse( stdRegNoList, stdCoursesList, regNo, cCode );
                        cout << "The course has been un-registered successfully";
                        break;

                    case 12:
                        while ( !relogin ) {
                            cout << "You have logged out of the system successfully." << endl;
                            cout << "You have to login to the system again to get access." << endl;
                            cout << "Username: ";
                            cin  >> loginUser;
                            cout << "Password: ";
                            cin  >> loginPass;

                            if( loginAuth( usersList, passwordsList, loginUser, loginPass ) ) {
                                cout << endl << "Logged in succesfully.";
                                relogin = true; 
                            }
                            else {
                                cout << endl << "Login Failed. Try again." << endl;
                            }
                        }
                        break;
                    
                    case 13:
                        cout << "Storing data for future use..." << endl;
                        storeCourses( courseCode, creditHrs, semester, courseName );

                        if ( storeCourses( courseCode, creditHrs, semester, courseName ) ) {
                            cout << "The data has been stored." << endl;
                        }
                        else {
                            cout << "Error in storing data. File not found";
                        }
                        programExit = true;
                        cout << "Program exited successfully.";
                }
            }
        }
    return 0;
    }

    // ********** FUNCTIONS **********

    // Adds a new course.
    void AddCourse( string code[], int creditHrs[], int semester [], string name[], string cCode, string cName, int crdHrs, int cSemester ) {
        
        string currCode, currName;
        int currSemester, creditH;
        int counter = findCounter(semester);
 
        cout << "Enter the details of the new course. " << endl;
        cout << "Enter details in the following sequence: " << endl << endl;
        cout << "For Example:" << endl;
        cout << "Course Code   Credit Hours    Semester    Course Name" << endl;
        cout << "PF232         3               3           Programming Fundamentals" << endl << endl;  
        cin >> currCode >> creditH >> currSemester;
        cin.ignore();
        getline(cin, currName);
        
        if( isValidCourse( currCode, creditH, currSemester, currName ) ) {
            CourseDetails( code, creditHrs, semester, name, counter, currCode, creditH, currSemester, currName ); // Adds details to arrays.
            cout << "The course has been added successfuly." << "\n";
        }
        else {
            cout << "\n" << "Invalid course details." << "\n";
        }
    }

    // Updates an already existing course.
    void EditCourse( string code[], int creditHrs[], int semester [], string name[], string cCode, string cName, int crdHrs, int cSemester ) {
        
        string currCode, currName;
        int currSemester, creditH, index, counter;
        cout << "Enter the code of the course you want to edit/update: ";
        cin  >> currCode;
            
            if( isValidCourseCode( currCode ) ) {
                index = findIndex(code, currCode, semester);
                
                if( index == -1 ) {     // -1 indicates that no already existing course matched the given course code. 
                    cout << "\n" << "The course does not exist." << "\n";
                }    
                else {
                    counter = index;
                    cout << "Enter the details of the new course: ";
                    cin  >> currCode >> creditH >> currSemester;
                    cin.ignore();
                    getline( cin, currName );
                        
                    if( isValidCourse( currCode, creditH, currSemester, currName ) ) {	
                        CourseDetails( code, creditHrs, semester, name, counter, currCode, creditH, currSemester, currName );
                        cout << endl << "\n" << "The course has been edited successfully." <<"\n";
                    }
                    else {
                        cout << "Invalid course details.";
                    }
                }				
            }	
    }

    // Deletes an existing course. 
    void DeleteCourse ( string code[], int creditHrs[], int semester[], string name[] ) {
        
        int index, counter;
        string delCode;
        counter = findCounter(semester);
        cout << "Enter the code of the course you want to delete: ";
        cin >> delCode;
        
        if( isValidCourseCode( delCode ) ) {
            index = findIndex( code, delCode, semester );
                    
            if(index == -1) {
                cout << "The course does not exist.";
            }
            else {

                for( index; index<counter; index++ ) {  // Shifts the value of next courses in place of deleted courses.
                    code[index] = code[index+1];
                    creditHrs[index] = creditHrs[index+1];
                    semester[index] = semester[index+1];
                    name[index] = name[index+1];
                }
                code[counter] = '\0';
                creditHrs[counter] = 0;
                semester[counter] = 0;
                name[counter] = '\0';
                cout << "\n" << "The course has been deleted successfully." << "\n";
            }
        }
        else {
            cout << "Invalid course code." << endl << endl;
        }
    }

    // Displays all the added courses.
    void ViewCourses( string code[], int creditHrs[], int semester[], string name[] ) {
        
        int counter = findCounter( semester );
        cout << "     " << setw(15) << left << "Course Code" << setw(25) << left << "Name" << setw(15) << left << "Credit Hours" << setw(10) << left << "Semester" << endl;
        
        for( int i=0; i<counter; i++ ) {
            cout << "     " << setw(15) << left << code[i] << setw(25) << left << name[i] << setw(15) << left << creditHrs[i] << setw(10) << left << semester[i] << endl;
        }
    }

    // Displays all the courses of a particular semester.
    void ViewSemesterCourses( string code[], int creditHrs[], int semester[], string name[], int semesterCourses ) {
        
        int counter = findCounter( semester );
        bool courseExists = false; // To check if atleast one course exists in the semester.
        cout << "     " << setw(15) << left << "Course Code" << setw(25) << left << "Name" << setw(15) << left << "Credit Hours" << setw(10) << left << "Semester" << endl;

        for( int i=0; i<counter; i++ ) {

            if( semester[i]==semesterCourses ) {
                cout << "     " << setw(15) << left << code[i] << setw(25) << left << name[i] << setw(15) << left << creditHrs[i] << setw(10) << left << semester[i] << endl;
                courseExists = true; // Flag.
            }
        }

        if( !courseExists ) {
            cout << "\n" << "Sorry, there is no course added in this semester." << "\n";
        }
    }

    // Adds the details of the new course. Used in add and edit functions.
    void CourseDetails( string code[], int creditHrs[], int semester[], string name[], int counter, string currCode, int creditH, int currSemester, string currName  ){

            code[counter]=currCode;
            creditHrs[counter]=creditH;
            semester[counter]=currSemester;
            name[counter]=currName;
    }

    // Displays all students.
    void ViewStudents ( string stdNamesList[], string stdRegNoList[], string stdCoursesList[100][100] ) {

        int stdCounter = findStdCounter( stdRegNoList );
        cout << endl << "     " << setw(15) << left << "Student Name" << setw(25) << left << "Registration Number" << setw(15) << left << "" << setw(10) << left << "" << endl;
        
        for( int i=0; i<stdCounter; i++ ) {
            cout << "     " << setw(15) << left << stdNamesList[i] << setw(25) << left << stdRegNoList[i] << setw(15) << left << "" << setw(10) << left << "" << endl;

            int courseCounter = findStdCourseCounter( stdCoursesList, i );
            cout << "     " << setw(15) << left << "Courses:" << ""  ;  

            for ( int j=0; j<courseCounter; j++) {    
                cout << right << stdCoursesList[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // Stores the courses in an external file when the program exits.
    bool storeCourses( string code[], int creditHrs[], int semester[], string name[] ) {
        ofstream courseData, storeCounter;
        bool coursesSaved;
        int counter = findCounter( semester );
        courseData.open("Courses.txt");

        if( courseData.is_open() ) { 
     
            for ( int i=0; i<counter; i++ ) {
                
                if( counter-i == 1 ) {  // Avoids "endl" in the last line which can cause errors.
                    courseData << code[i] << "," << creditHrs[i] << "," << semester[i] << "," << name[i];
                }
                else {
                    courseData << code[i] << "," << creditHrs[i] << "," << semester[i] << "," << name[i] << endl;
                }
            }
            coursesSaved = true;
            courseData.close();
        }
        else {
            coursesSaved = false;
        }

    return coursesSaved;
    }

    // Loads the already present courses when the program starts.
    bool loadCourses( string code[], int creditHrs[], int semester[], string name[] ) {

        ifstream courseInput;
        string line;
        bool coursesLoaded;
        int counter=0;
        courseInput.open("Courses.txt");

        if( courseInput.is_open() ) {

            while ( !courseInput.eof() ) {
                getline( courseInput, line );
                string inputCode, inputName;
                int inputSemester, inputCredit;
                int character = 0;
                
                for( character; line[character]!=','; character++ ) {
                    inputCode += line[character];
                }
                code[counter] = inputCode;
                character++;
                
                for( character; line[character]!=','; character++ ) {
                    inputCredit = line[character] - '0';
                }
                creditHrs[counter] = inputCredit;
                character++;

                for( character; line[character]!=','; character++ ) {
                    inputSemester = line[character] - '0';
                }
                semester[counter] = inputSemester;
                character++;

                for( character; character<line.length(); character ) {
                    inputName += line[character];
                    character++;
                }
                name[counter] = inputName;
                counter++;
            }
            coursesLoaded = true;
            courseInput.close();
        }
        else {
            coursesLoaded = false;
        }
    return coursesLoaded;
    }

    // Adds a new student.
    void AddStudent( string stdNamesList[], string stdRegNoList[], string studentName, string regNo ) {
        
        int stdCounter = findStdCounter( stdRegNoList );
        stdNamesList[stdCounter] = studentName;
        stdRegNoList[stdCounter] = regNo;
    }

    // Update student.
    void UpdateStudent ( string stdNamesList[], string stdRegNoList[], string studentName, string regNo ) {

            int index = findStdIndex( stdRegNoList, regNo );
            updateStudentDetails ( index, stdNamesList, stdRegNoList, studentName, regNo );
    }

    // Deletes a student.
    void DeleteStudent( string stdNamesList[], string stdRegNoList[], string studentName, string regNo ) {

            int index = findStdIndex( stdRegNoList, regNo );
            int stdCounter = findStdCounter (stdRegNoList);

            for( index; index<stdCounter; index++ ) {  // Shifts the value of next courses in place of deleted courses.
                stdNamesList[index] = stdNamesList[index+1];
                stdRegNoList[index] = stdRegNoList[index+1];
            }
            stdRegNoList[stdCounter] = "0";
            stdNamesList[stdCounter] = "0";
    }

    // Updates the details of the student. Used in update student function.
    void updateStudentDetails ( int index, string stdNamesList[], string stdRegNoList[], string studentName, string regNo ) {
           
            cout << "Enter the new details of the student : ";
            cin  >> regNo;
            cin.ignore();
            getline( cin, studentName );

            if ( !isValidStudentName(studentName) ) {
                cout << "Student name is not valid.";
            }
            stdNamesList[index] = studentName;
            stdRegNoList[index] = regNo;
    }

    // This function checks if given courseCode is in courseCodeList or not. If yes, then adds it in stdCoursesList against student�s index.
    void RegisterCourse( string stdRegNoList[], string stdCoursesList[100][100], string courseCode[], string regNo, string cCode ) {

            int index, stdCourseCount;
            index = findStdIndex( stdRegNoList, regNo ); 
            stdCourseCount = findStdCourseCounter( stdCoursesList, index );
            stdCoursesList[index][stdCourseCount] = cCode;
    }

    // This function un-registers an added course.
    void unRegisterCourse( string stdRegNoList[], string stdCoursesList[100][100], string regNo, string cCode ) {
        int stdIndex, stdCourseIndex, stdCounter;
        stdIndex = findStdIndex( stdRegNoList, regNo );
        stdCounter = findStdCourseCounter( stdCoursesList, stdIndex );
        stdCourseIndex = findStdCourseIndex ( stdCoursesList, cCode, stdRegNoList, regNo );

          for( stdCourseIndex; stdCourseIndex<stdCounter; stdCourseIndex++ ) {  // Shifts the value of next courses in place of deleted courses.
                stdCoursesList[stdIndex][stdCourseIndex] = stdCoursesList[stdIndex][stdCourseIndex+1];
            }
            stdCoursesList[stdIndex][stdCounter] = "0";
    }

    // For login and authenticatiion.
    bool loadUsers( string usersList[] , string passwordsList[] ) {

    bool valid;
    ifstream loginData;
    loginData.open( "Users.txt" );
    string line, userName, passWord;
    
        if( !loginData.is_open() ) {        // To check if the file exists.        
            valid = false;
        }
        else {

            while( !loginData.eof() ) {
                getline(loginData, line);
                int counter = 0;

                while( line[counter]!=',' ) {
                    userName += line[counter];
                    counter++;
                }
                usersList[counterUsers] = userName;
                counter++;
                
                while( counter < line.length() ) {
                    passWord += line[counter];
                    counter++;
                }
                passwordsList[counterUsers]=passWord;
                counterUsers++;
                userName="";
                passWord="";
            }
        valid = true;
        }
    loginData.close();
    return valid;
    }

    // To check login credentials.
    bool loginAuth( string usersList[], string passwordsList[], string loginUser, string loginPass ) { 

        string addedUser, addedPass;
        bool validUser=true, validPass=true, login;

        for ( int i=0; i<counterUsers; i++ ) {
            addedUser = usersList[i];
            addedPass = passwordsList[i];
            
                if( loginUser == addedUser ) {
                    validUser=true;
                }
                else {
                    validUser=false;
                }

                if( loginPass==addedPass ) {
                    validPass=true;
                }
                else {
                    validPass=false;
                }

            if( validUser && validPass ) {
                login = true;
                break;
            }
            else {
                login = false;
            }
        }
    return login;
    }
    
    // To find the index of the already added course for update or delete purposes.
    int findIndex( string code[] , string currCode, int semester[] ) {

        int index = -1;         // If no course exists with the same course code.
        string compCode;
        bool indexMatch;
        int counter = findCounter( semester );
        
        for ( int i=0; i<counter; i++ ) {
            compCode=code[i];
            
            for( int j=0; j<=compCode.length(); j++ ) {
                
                if( compCode[j] == currCode[j] ) {
                    indexMatch = true;
                }
                else {
                    indexMatch = false;
                    break;
                }
            }
            
            if ( indexMatch == true ) {
                index = i;
                break;
            }
        }
        return index;
    }

    // Finds the number courses already present.
    int findCounter ( int semester[] ) {

        int counter = 0;

        for ( int i=0; i<100; i++ ) {

            if (semester[i]==0) {
                counter = i;
                break;
            }
        }
    return counter;
    }

    // Finds the number of students already present.
    int findStdCounter ( string stdRegNoList[] ) {

        int stdCounter = 0; 

        for ( int i=0; stdRegNoList[i]!="0"; i++ ) {
            stdCounter = i+1;
        }
    return stdCounter;
    }

    // Finds index of student from the given student registraion number.
    int findStdIndex ( string stdRegNoList[], string regNo ) {

        string compRegNo;
        bool indexMatch;
        int index = -1, counter = findStdCounter( stdRegNoList );

        for ( int i=0; i<counter; i++ ) {
            compRegNo = stdRegNoList[i];
            
            for( int j=0; j<=compRegNo.length(); j++ ) {
                
                if( compRegNo[j] == regNo[j] ) {
                    indexMatch = true;
                }
                else {
                    indexMatch = false;
                    break;
                }
            }
            if ( indexMatch ) {
                index = i;
                break;
            }
        }
    return index;
    }

    // Finds the counter value for the 2D array. 
    int findStdCourseCounter( string stdCoursesList[100][100], int stdIndex ) {
        
        int stdCourseCounter = 0;

        for ( int i=0; stdCoursesList[stdIndex][i]!="0"; i++ ) {
            stdCourseCounter = i+1;
        }
    return stdCourseCounter;
    }

    // Finds the specified course index in the 2D array in unregisteration of courses.
    int findStdCourseIndex( string stdCoursesList[100][100], string cCode, string stdRegNoList[], string regNo ) {

        int index = -1;
        string compCode;
        bool indexMatch;
        int stdIndex = findStdIndex( stdRegNoList, regNo ); 
        int counter = findStdCourseCounter( stdCoursesList, stdIndex );
        
        for ( int i=0; i<counter; i++ ) {
            compCode=stdCoursesList[stdIndex][i];
            
            for( int j=0; j<=compCode.length(); j++ ) {
                
                if( compCode[j] == cCode[j] ) {
                    indexMatch = true;
                }
                else {
                    indexMatch = false;
                    break;
                }
            }
            
            if ( indexMatch == true ) {
                index = i;
                break;
            }
        }
    return index;
    }

    // **** Validators ****
   
    // To see if character input is valid.
    bool isValidCh( char validCh ) {

            bool valid;
            
                if( validCh>='A' && validCh <='Z' || validCh >= 'a' && validCh <= 'z' ){
                        valid = true;
                    }
                else {
                        valid = false;
                }		 
    return valid;
    }

    // To check if digit input is valid.
    bool isValidDig( char validDig ) {

        bool valid;
        
        if ( validDig >= '0' && validDig <= '9' ) {
            valid = true;
        }
        else {
            valid = false;
        }

    return valid;
    }

    // To check if course name string is valid.
    bool isValidCourseName( string name ) {

        bool valid, validC, validL;
        
        if ( name.length() <= 50 ) {  // Check name length.
            validL=true;
        }
        else {
            validL=false;
        }
        
        for( int i=0; i<name.length(); i++ ) {
        
            if( isValidCh( name[i] ) || (name[i]==' ') ) {
                validC = true;
            }
            else{
                validC = false;
            }
        }
        
        if( validL && validC ) {
            valid = true;
        }
        else {
            valid = false;
        }
    return valid;
    }

    // To check if student name is valid.
    bool isValidStudentName(string stdName) {

        bool valid, validC, validL;
        
        if ( stdName.length() <= 50 ) {  // Check name length.
            validL=true;
        }
        else {
            validL=false;
        }
        
        for( int i=0; i<stdName.length(); i++ ) {
        
            if( isValidCh( stdName[i] ) || (stdName[i]==' ') ) {
                validC = true;
            }
            else{
                validC = false;
            }
        }
        
        if( validL && validC ) {
            valid = true;
        }
        else {
            valid = false;
        }
    return valid;
    }

    // To check if course code is valid.
    bool isValidCourseCode(string code) {
        
        bool valid, validL, validC, validD;
        
        if ( code.length() == 5 ) {  // Check code length.
            validL = true;
        } 
        else {
            validL = false;
        }
        
        for ( int i=0; i<2; i++ ) {  // Check first two alphabets.
            
            if( isValidCh( code[i] ) ) { 
                validC = true;
            }
            else {
                validC = false;
                break;
            }
        }
        
        for( int i=2; i<5; i++ ) {  // Check last three digits.
            
            if( isValidDig( code[i] ) ) {
                validD = true;
            }
            else {
                validD = false;
            }	
        }
        
        if( validL && validC && validD ) {
            valid = true;
        } 
        else {
            valid = false;
        }
    return valid;
    }

    // To check if student registration number is valid or not.
    bool isValidRegNumber( string regNo ) {

        bool valid = false;

        if ( (regNo[0] == '2') && (regNo[1]=='0') && (regNo[2]=='1') && isValidDig(regNo[3]) ) {    // Year check.
            if ( isValidCh(regNo[5]) && isValidCh(regNo[6]) ) {                                     // Dept. check. 
                if( isValidDig(regNo[8]) && isValidDig(regNo[9]) && isValidDig(regNo[10]) ) {       // Roll. no check.
                    valid = true;
                }
            }
        }
    return valid;
    }

    // To check if semester input is between 0 and 9.
    bool isValidSemester( int semester ) {

        bool valid;
        
        if ( semester>0 && semester<9 ) {
            valid = true;	
        }
        else {
            valid = false;
        }
    return valid;
    }

    // Validates the credit hours.
    bool isValidCreditHours( int creditHours ) {
            
            bool valid;
            
            if ( creditHours>0 && creditHours<4 ) {
                valid = true;	
            }
            else {
                valid = false;				
            }
    return valid;
    }

    // Combines all the above validators to verify the input in one go.
    bool isValidCourse( string currCode, int creditH, int currSemester, string currName ) {
        bool valid;
        
                if( isValidCourseCode(currCode) ) {
                   if ( isValidCreditHours(creditH) ) {
                        if ( isValidSemester(currSemester) ) {
                            if ( isValidCourseName(currName) ) {
                                valid = true;
                            }			
                            else {
                                valid = false;
                            }					
                        }	
                    }
                }
    return valid;		
    }