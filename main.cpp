#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
using namespace std;


class Calculator
{
private:
    double _Result;
    vector<double> _PreviousResultsHistory;
    enum _Operation {ADD = 1 , SUBTRACT , DIVIDE , MULTIPLY , CANCEL_LAST_OPERATION , CLEAR , NONE};
    _Operation _TheLastOperation =  _Operation::NONE;


    string _OperationName(const _Operation& _TheLastOperation) const
    {
        switch (_TheLastOperation)
        {

            case _Operation::ADD: return "Add";
            case _Operation::SUBTRACT: return "Subtract";
            case _Operation::DIVIDE: return "Divide";
            case _Operation::MULTIPLY: return "Multiply";
            case _Operation::CANCEL_LAST_OPERATION: return "Cancel Last Operation";
            case _Operation::CLEAR: return "Clear";
            case _Operation::NONE: return "";


            default: return "";
        }
    }
    _Operation _ReadOperationNumber(const string& msg) const
    {
        short operationNumber;
        cout << msg;
        cin >> operationNumber;

        return (_Operation)operationNumber;
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

    void _DisplayOperatinsMenu() const   
    {
        cout << "\n--------------------------------------------------\n";
        cout << "The Available Operations: \n";
        cout << "\n--------------------------------------------------\n";
        cout << "(0).Exite\n";
        cout << "(1).Add\n";
        cout << "(2).Subtract\n";
        cout << "(3).Divide\n";
        cout << "(4).Multiply\n";
        cout << "(5).Cancel Last Operation\n";
        cout << "(6).Clear\n";
        cout << "\n--------------------------------------------------\n";

    }


    void _ExecuteOperation(const _Operation& operation , const double& number = 0)
    {
        switch (operation)
        {
            case _Operation::ADD : add(number); break;
            case _Operation::SUBTRACT : subtract(number); break;
            case _Operation::DIVIDE :
            {
                try
                {
                    divide(number);
                    break;
                }
                catch(const exception& exp)
                {
                    cerr << exp.what() << '\n';
                    break;
                }
            }  
            case _Operation::MULTIPLY : multiply(number); break;
            case _Operation::CANCEL_LAST_OPERATION : cancelLastOperation(); break;
            case _Operation::CLEAR : clear(); break;
        
            
        
            default: break;
            
        }
    }

public:

    Calculator(const double& initilizeValue = 0){_Result = initilizeValue;}

    void add(const double& numberToAdd)
    {
        _PreviousResultsHistory.push_back(_Result);
        _Result += numberToAdd;
        _TheLastOperation = _Operation::ADD;
    }

    void subtract(const double& numberToSubtract)
    {
        _PreviousResultsHistory.push_back(_Result);
        _Result -= numberToSubtract;
        _TheLastOperation = _Operation::SUBTRACT;
    }

    void divide(const double& numberToDivide)
    {
        _PreviousResultsHistory.push_back(_Result);
        if(numberToDivide == 0)
            throw runtime_error("Can NOT Divide On Zero!!");

        _Result /= numberToDivide;
        _TheLastOperation = _Operation::DIVIDE;
    }

    void multiply(const double& numberToMutiply)
    {
        _PreviousResultsHistory.push_back(_Result);
        _Result *= numberToMutiply;
        _TheLastOperation = _Operation::MULTIPLY;
    }

    void clear()
    {
        
        _PreviousResultsHistory.push_back(_Result);
        _Result = 0;
        _TheLastOperation = _Operation::CLEAR;
    }

    void printResult() const 
    {
        if(_TheLastOperation != _Operation::NONE)
            cout << "\nThe Result After " << _OperationName(_TheLastOperation) << " Is: ";
        else
            cout << "\nThe Result Is: ";

        cout << "(" << _Result << ")"<< endl;
    }

    void cancelLastOperation()
    {
        if(_PreviousResultsHistory.size() == 0)
            throw runtime_error("Can NOT Cancel None Operator!!");
        size_t lastResultIndex = _PreviousResultsHistory.size() - 1;
        _Result = _PreviousResultsHistory[lastResultIndex];
        _PreviousResultsHistory.pop_back();
    }

    double finalResult(){return _Result;}

    void run()
    {
        do
        {
            cout << "\n\n--------------------The Current result(" << _Result << ")--------------------\n\n";

            _DisplayOperatinsMenu();

            _Operation operation = _ReadOperationNumber("Please Enter What Do You Whant To Do Here: ");

            if(operation == 0)
            {
                break;
            }

            else if(operation == _Operation::CLEAR || operation == _Operation::CANCEL_LAST_OPERATION ||operation == _Operation::NONE)
            {
                _ExecuteOperation(operation);
            }
            else
            {
                double value = _ReadNumber("Please Enter The Value Here : ");

                _ExecuteOperation(operation , value);
            }

            cout << "\nOperation Perform Successifuly\n";


            
        } while (true);
        
    }
};



  
int main()  
{
    Calculator calc;
    calc.run();

    
    return 0;  
}