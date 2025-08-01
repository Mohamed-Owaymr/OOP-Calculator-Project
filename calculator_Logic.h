#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Calculator
{
private:
    double _Result;
    vector<double> _PreviousResultsHistory;
    enum _Operation {EXIT , ADD , SUBTRACT , DIVIDE , MULTIPLY , CANCEL_LAST_OPERATION , CLEAR , PRINT_RESULT ,  NONE};
    _Operation _TheLastOperation =  _Operation::NONE;


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


    void cancelLastOperation()
    {
        if(_PreviousResultsHistory.size() == 0)
            throw runtime_error("Can NOT Cancel None Operator!!");
        size_t lastResultIndex = _PreviousResultsHistory.size() - 1;
        _Result = _PreviousResultsHistory[lastResultIndex];
        _PreviousResultsHistory.pop_back();
    }

    void executeOperation(const _Operation& operation , const double& number = 0)
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

    double result(){return _Result;}

    void setTheLastOperation(const _Operation& theLastOperation){_TheLastOperation = theLastOperation;}
    _Operation theLastOperation(){return _TheLastOperation;}

   
    friend class CalculatorUI;
};