#pragma once

#include <stack>

using namespace std;

class clsMyString
{

private :

    stack<string> _Under;
    stack<string> _Redo;
    string _Value;

public :

    void SetValue(string value)
    {
        _Under.push(_Value);
        _Value = value;
    }

    string Value()
    {
        return _Value;
    }

    void Undo()
    {
        if(!_Under.empty())
        {
            _Redo.push(_Value);
            _Value = _Under.top();
            _Under.pop();

        }

    }

    void Redo()
    {
        if(!_Redo.empty())
        {
            _Under.push(_Value);
            _Value = _Redo.top();
            _Redo.pop();

        }

    }


};
