#pragma once
#include "calculator_Logic.h"
#include <stdexcept>
#include <limits>
using namespace std;

class CalculatorUI
{
private:
    Calculator calculatorLogic;
    void _DisplayOperatinsMenu() const   
    {
        cout << "\n--------------------------------------------------\n";
        cout << "The Available Operations:";
        cout << "\n--------------------------------------------------\n";
        cout << "(0).Exite\n";
        cout << "(1).Add\n";
        cout << "(2).Subtract\n";
        cout << "(3).Divide\n";
        cout << "(4).Multiply\n";
        cout << "(5).Cancel Last Operation\n";
        cout << "(6).Clear\n";
        cout << "(7).Print Result";
        cout << "\n--------------------------------------------------\n";

    }
    Calculator::_Operation _ReadOperationNumber(const string& msg) const
    {
        short operationNumber;
        cout << msg;
        cin >> operationNumber;

        return (Calculator::_Operation)operationNumber;
    }
    double _ReadNumber(const string& msg) const
    {
        double number;
        cout << msg;
        cin >> number; 
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value Input!!\n";
            cout << msg;
            cin >> number;
        }       
        return number;
    }

    string _OperationName(const Calculator::_Operation& _TheLastOperation) const
    {
        switch (_TheLastOperation)
        {

            case Calculator::_Operation::ADD: return "Add";
            case Calculator::_Operation::SUBTRACT: return "Subtract";
            case Calculator::_Operation::DIVIDE: return "Divide";
            case Calculator::_Operation::MULTIPLY: return "Multiply";
            case Calculator::_Operation::CANCEL_LAST_OPERATION: return "Cancel Last Operation";
            case Calculator::_Operation::CLEAR: return "Clear";
            case Calculator::_Operation::NONE: return "";


            default: return "";
        }
    }
    void _PrintResult() const 
    {
        if(calculatorLogic._TheLastOperation != Calculator::_Operation::NONE)
            cout << "\nThe Result After " << _OperationName(calculatorLogic._TheLastOperation) << " Is: ";
        else
            cout << "\nThe Result Is: ";

        cout << "(" << calculatorLogic._Result << ")"<< endl;
    }

public:
    
    
    void run()
    {
        
        _DisplayOperatinsMenu();
        do
        {
            
            Calculator::_Operation operation = _ReadOperationNumber("Please Enter What Do You Whant To Do Here: ");

            if(operation == Calculator::_Operation::EXIT)
                break;

            else if(operation == Calculator::_Operation::CLEAR ||
                    operation == Calculator::_Operation::CANCEL_LAST_OPERATION ||
                    operation == Calculator::_Operation::NONE)
            {
                calculatorLogic.executeOperation(operation);
            }
            else if(operation == Calculator::_Operation::PRINT_RESULT)
            {
                _PrintResult();
            }
            else
            {
                double value = _ReadNumber("Please Enter The Value Here : ");

                calculatorLogic.executeOperation(operation , value);
            }
            
            cout << "\n\nOperation Perform Successifuly\n\n";


            
        } while (true);
        
    }

};