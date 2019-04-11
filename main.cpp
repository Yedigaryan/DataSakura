#include <iostream>
#include <string>
using namespace std;

#define SAFE_DELETE(p)  if((p) != NULL){ delete (p); (p) = NULL;}

// implement your class here
class Printer
{
public:

    Printer()
    {
        Clear();
    }

    void Clear()
    {
        m_iValue = NULL;
        m_fValue = NULL;
        m_cValue = NULL;
        m_dValue = NULL;
        m_strValue = "";
        m_pointer_or_not = false;
    }

    Printer& operator=(int value)
    {
        Clear();
        m_pointer_or_not = false;
        m_iValue = &value;
        return *this;
    }

    Printer& operator=(int* value)
    {
        Clear();
        m_pointer_or_not = true;
        m_iValue = value;
        return *this;
    }

    Printer& operator=(float value)
    {
        Clear();
        m_pointer_or_not = false;
        m_fValue = &value;
        return *this;
    }

    Printer& operator=(float* value)
    {
        Clear();
        m_pointer_or_not = true;
        m_fValue = value;
        return *this;
    }

    Printer& operator=(char value)
    {
        Clear();
        m_pointer_or_not = false;
        m_cValue = &value;
        return *this;
    }

    Printer& operator=(char* value)
    {
        Clear();
        m_pointer_or_not = true;
        m_cValue = value;
        return *this;
    }

    Printer& operator=(double value)
    {
        Clear();
        m_pointer_or_not = false;
        m_dValue = &value;
        return *this;
    }

    Printer& operator=(double* value)
    {
        Clear();
        m_pointer_or_not = true;
        m_dValue = value;
        return *this;
    }

    Printer& operator=(const string& value)
    {
        Clear();
        m_strValue = value;
        return *this;
    }

    void print()
    {
        if(m_iValue)
        {
            if(m_pointer_or_not)
              cout << "[" << *m_iValue <<"]" << endl;
            else
               cout << *m_iValue << endl;

        }
        if(m_fValue)
        {
            if(m_pointer_or_not)
              cout << "[" << *m_fValue <<"]" << endl;
            else
               cout << *m_fValue << endl;

        }
        if(m_dValue)
        {
            if(m_pointer_or_not)
              cout << "[" << *m_dValue <<"]" << endl;
            else
               cout << *m_dValue << endl;

        }
        if(m_cValue)
        {
            if(m_pointer_or_not)
              cout << "[" << *m_cValue <<"]" << endl;
            else
               cout << *m_cValue << endl;

        }
        if(!m_strValue.empty())
        {
            cout << m_strValue << endl;
        }
    }

private:
    int* m_iValue;
    float* m_fValue;
    char* m_cValue;
    double* m_dValue;
    string m_strValue;

    bool m_pointer_or_not;
};



int main() {
    Printer printer;

    printer = 42;
    printer.print(); //should print "42" to standard output

    int* value = new int(10);
    printer = value;
    printer.print(); // should print "[10]"



    *value = 20; // the value pointer did not change, changed a value by it
    printer.print(); // should print "[20]"


    float* fvalue = new float(9.81);
    printer = fvalue;
    printer.print(); // should print "[9.81]"


    *fvalue = 0.2+0.3;
    printer.print(); // should print "[0.5]"



    printer = std::string("Hello world");
    printer.print();
    //should print "Hello world"

    printer = 2.718281;
    printer.print();
    //should print "2.718281"

    delete fvalue;
    delete value;

    return 0;
}


// the standard output should be:
//42
//[10]
//[20]
//[9.81]
//[0.5]
//Hello world
//2.71828
