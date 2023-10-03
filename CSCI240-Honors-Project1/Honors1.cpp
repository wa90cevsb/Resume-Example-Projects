/***************************************************************
CSCI 297      Honors Program 1     Fall 2023

Programmer: Jonathan Whybrew
Z Number: Z2011392

Date Due: Sep 29th, 2023

Purpose: This program administers and grades a randomized
    math quiz.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void StartQuiz(int diff, int problemType);
int ChangeProblemType(int *problemType);


/***********************************************
 *                   main                      */
int main()
{
    // Initialization for program
    int exit = 0;
    int problemType = 0;
    int invalidOpt = 0;
    string input;
    char input_char;
    const string PROBLEM_TYPES[] = {"random", "addition", "multiplication"};
    cout << fixed << setprecision(2);

    // Main loop
    do
    {
        // Print out main menu
        cout << endl
             << "------------------------------" << endl
             << "     Main Menu" << endl
             << "    1. Easy mode" << endl
             << "    2. Hard mode" << endl
             << "    3. Change problem type" << endl
             << "    4. Quit" << endl << endl;

        // If last selection was invalid
        if (invalidOpt)
        {
            cout << "Invalid option";

            // 2 is the return code from the select problem type menu
            if (invalidOpt==2)
                cout << ", problem type is " << PROBLEM_TYPES[problemType];
            
            // 1 is the invalid opt flag of the main loop
            else
                cout << " ...";
            
            // Clear flag
            cout << endl;
            invalidOpt = 0;
        }

        // Selection instruction
        cout << "Type number for selection: ";
        
        // Wait for the user to enter a value
        cin >> input;
        input_char = input.c_str()[0];
        
        // Check what key was pressed
        switch (input_char)
        {
            // Option 1 or Option 2:
            //  Start the quiz with difficulty and problemType arguments
            case '1': case '2':
                StartQuiz(input_char, problemType);
                break;

            // Option 3:
            //  Go to problem type menu
            case '3':
                cout << endl << endl << endl;
                invalidOpt = ChangeProblemType(&problemType);
                break;

            // Option 4:
            //  Make exit flag true so that the program quits
            case '4':
                exit = 1;
                break;

            // Unknown option, set invalidOpt flag
            default:
                invalidOpt = 1;
                break;
        }
    // Repeat main loop until exit condition is true
    } while(!exit);

    return 0;
}


/***********************************************
 *                 StartQuiz                   */
void StartQuiz(int diff, int problemType)
{
    // Variables to be used in the quiz function
    int problem, a, b, ans;
    int grade = 0;
    char opSign;
    string input;

    // Set the seed to something random
    srand(time(0));

    // Loop through 8 different problems
    for (int i=0; i<8; i++)
    {
        // Set problem type if a random type is needed
        if (!(problem = problemType))  problem = (rand()%2)+1;

        //  problem == 1   means addition
        if (problem == 1)
        {
            // Easy difficulty, numbers 0-20
            if (diff == '1')
            {
                a = rand() % 21;
                b = rand() % 21;
            }
            // Hard difficulty, numbers 0-75
            else
            {
                a = rand() % 76;
                b = rand() % 76;
            }
            // Set correct answer and operator
            ans = a+b;
            opSign = '+';
        }
        else
        {
            // Easy, a <= 10 and b <= 5
            if (diff == '1')
            {
                a = rand() % 11;
                b = rand() % 6;
            }
            // Hard, nums are <= 20
            else
            {
                a = rand() % 21;
                b = rand() % 21;
            }
            // Set correct answer and operator
            ans = a*b;
            opSign = 'x';
        }

        // Format problem
        cout << setw(5) << a << endl
             << opSign << setw(4) << b << endl
             << "-----" << endl;

        // Get input from user
        cin >> input;
        
        // Check input and provide feedback
        if (atoi(input.c_str()) == ans)
        {
            grade++;
            cout << endl << "Correct!";
        }
        else
        {
            cout << endl << "Incorrect, " << a << opSign << b << " = " << ans;
        }

        cout << endl << endl;
    }

    // End of 8 problem loop, show score and grade
    cout << endl << "Your score:  " << grade << " / 8";
    cout << endl << setw(17) << (grade/8.0)*100 << "%";
}


/***********************************************
 *            ChangeProblemType                */
int ChangeProblemType(int *problemType)
{
    string input;
    char input_char;

    // Print menu
    cout << "------------------------------" << endl
         << "  Problem Type Menu" << endl
         << "     1. Random"      << endl
         << "     2. Addition"    << endl
         << "     3. Multiplication" << endl << endl
         << "Type number for selection: ";

    // Get input
    cin >> input;
    input_char = input.c_str()[0];

    // Check user input
    switch (input_char)
    {
        // Sets the problem type pointer to the selected value
        case '1': case '2': case '3':
            *problemType = input_char - 0x31;
            return 0;
            break;

        // Return 2 back to main(), because 2 sets the invalidOpt flag
        default:
            cout << endl << endl << endl;
            return 2;
            break;
    }

    // Shouldn't reach here
    return 2;
}