#include<iostream>
#include<cstdlib> //to use system("pause"); and backward compatibility
#include "Input_Validation.h" //template class for input validation
#include<conio.h>//Library used for WaitKey() pausing execution
#include<windows.h>//for setting color
#include<iomanip>//for setprecision() calls
using namespace std;
void welcomeMessage()
{
     cout << "\nWelcome to our grade average calculation program!!" << endl; 
}
 
/***************  
   Function to validate double input 
************************/
double  acceptValidInputDouble(double &input)
{
        while (true)
        {
             
            try
            {
                input = getValidatedInput<double>();
            }
            catch (exception e)
            {
                cerr << "Invalid input: please enter a number." << endl;
                continue;
            }
             
            if(input < 0.00)
            {
                cout << "Grade must be greater than zero. Please try again: " <<; 
            }
            else
            {
                break;
            }
        }
         
        return input; 
}
 
/***************  
   Function to validate integer input 
************************/
int acceptValidInputInt(int &input)
{
        while (true)
        {
             
            try
            {
                input = getValidatedInput<int>();
            }
            catch (exception e)
            {
                cerr << "Invalid input: please enter a number (no decimals)." << endl;
                continue;
            }
     
            if(input < -1)
            {
                cout << "Grades number count must be positve. Please try again: "; 
            }
            else
            {
                break;
            }
        }
         
        return input; 
}
 
/***************  
   Function to set the color on screen
************************/
void setColor(int colorValue)
{
     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //For use of SetConsoleTextAttribute()
     SetConsoleTextAttribute(console, colorValue);
}
 
/***************  
   Function to populate the grades array
************************/
void populateGradesArray()
{
    int numberOfGrades = 0;
    double sum = 0.0; 
    double average = 0.0; 
     
    cout << fixed << setprecision(2); 
     
    do
    {
        welcomeMessage();
        cout << "\nHow many grades would you like to enter (-1 to exit)? > "; 
        numberOfGrades = acceptValidInputInt(numberOfGrades); 
        system("cls"); //clear screen
         
        if(numberOfGrades != -1)
        {
            cout << "Marvelous, I am happy to assit you in entering " << numberOfGrades << " grades." << endl << endl; 
             
            /* C++ does not advocate to return the address of a local variable to outside of 
            // the function so you would have to define the local variable as static variable.*/
            double gradesArray[numberOfGrades];
             
            for(int i = 0; i < numberOfGrades; i++)
            {
                    cout << "Please enter grade[" << (i + 1) << "]:"; 
                    gradesArray[i] = acceptValidInputDouble(gradesArray[i]); //validate input an populate array    
                    sum += gradesArray[i]; 
            }
             
            average = sum/numberOfGrades; 
            cout << "\nThe average of the grades is "; 
            setColor(10); //green
                cout << average; 
            setColor(7); //standard color
                
             /******************************************/
            //Using an array to sort Values Bubble Sort
            //Sorting values int the distance array descending from greatest to least
            //Nested for statements (loops within loops)
             double temp_value; //a variable to temporarily hold sorted number
             
             //These nested four statements sort the values in the array
             for (int b = 0; b < numberOfGrades; b++)
             {
                    for (int inner_loop_index =  b+1; inner_loop_index < numberOfGrades; inner_loop_index++)
                    {
                              
                        if (gradesArray[b] < gradesArray[inner_loop_index])  //< for descending
                        {
                           temp_value = gradesArray[b];
                           gradesArray[b] = gradesArray[inner_loop_index];
                           gradesArray[inner_loop_index] = temp_value; 
                        }
                    }        
             }
             
            //The for statement reprints the values in the array
            cout << "\n\nThe sorted gradesArray is as follows (DESC): " << endl << endl;
            cout << fixed;
             
            for(int c=0; c < numberOfGrades; c++)
            {
                cout << "gradesArray[" << c << "]= "; 
                setColor(10); //green
                    cout << setprecision (2) << gradesArray[c] << endl;
                setColor(7); //standard color
            }
        }
        else
        {
            setColor(10); //green
                cout << "Hasta la vista, baby!" << endl;
            setColor(7); //standard color 
        }
    }while(numberOfGrades != -1); //-1 is exit condition 
}
 
int main()
{
    populateGradesArray(); //function call to do the work of populating the grades array
    system("pause"); 
     
    return 0;    
}