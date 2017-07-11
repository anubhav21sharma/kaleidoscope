//============================================================================
// Name        : Parser.cpp
// Author      : Anubhav Sharma
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*----------------------- LEXER STUFF -----------------------*/
enum Token
{
    TK_EOF = -1,
    TK_DEF = -2,
    TK_EXTERN = -3,
    TK_IDENTIFIER = -4,
    TK_NUMBER = -5
};

static string identifierStr;
static double numVal;

static int gettok()
{
    static char lastchar = ' ';
    while (isspace(lastchar))
        lastchar = getchar();

    //Alphanumeric
    if (isalpha(lastchar))
    {
        identifierStr = string(1,lastchar);
        while (isalnum(lastchar = getchar()))
        {
            identifierStr += string(1,lastchar);
        }
        if (identifierStr == "def")
            return TK_DEF;
        if (identifierStr == "extern")
            return TK_EXTERN;
        return TK_IDENTIFIER;
    }
    //Numeric
    if (isdigit(lastchar) || lastchar == '.')
    {
        string numStr = string(1,lastchar);
        do
        {
            numStr += string(1,lastchar);
            lastchar = getchar();
        } while (isdigit(lastchar) || lastchar == '.');

        numVal = strtod(numStr.c_str(), nullptr);
        return TK_NUMBER;
    }
    //Comment
    if (lastchar == '#')
    {
        do
        {
            lastchar = getchar();
        } while (lastchar != EOF && lastchar != '\n' && lastchar != '\r');
        
        if(lastchar != EOF)
            return gettok();
    }
    if(lastchar==EOF)
        return gettok();

    int thischar = lastchar;
    lastchar = getchar();
    return thischar;
}

/*----------------------- PARSER STUFF -----------------------*/
class ExprAST
{
  public:
    virtual ~ExprAST()
    {
    }
};

class NumberExprAST : public ExprAST
{
    double val;

  public:
    NumberExprAST(double val) : val(val)
    {
    }
};

class VariableExprAST : public ExprAST
{
    string name;

  public:
    VariableExprAST(string &name) : name(name)
    {
    }
};

class BinaryExprAST : public ExprAST
{
    string op;
    unique_ptr<ExprAST> lhs;
    unique_ptr<ExprAST> rhs;

  public:
    BinaryExprAST(string op, unique_ptr<ExprAST> lhs, unique_ptr<ExprAST> rhs) : op(op), lhs(move(lhs)), rhs(move(rhs)) {}
};

class CallExprAST : public ExprAST
{
    string callee;
    vector<unique_ptr<ExprAST>> args;

  public:
    CallExprAST(const string &callee, vector<unique_ptr<ExprAST>> args) : callee(callee), args(move(args)) {}
};

class PrototypeAST
{
    string name;
    vector<string> args;

  public:
    PrototypeAST(const string &name, vector<string> args) : name(name), args(move(args)) {}
    const string &getName() const
    {
        return name;
    }
};

class FunctionAST
{
    unique_ptr<PrototypeAST> prototype;
    unique_ptr<ExprAST> body;

  public:
    FunctionAST(unique_ptr<PrototypeAST> prototype, unique_ptr<ExprAST> body) : prototype(move(prototype)), body(move(body)) {}
};

int main(void)
{
    cout << ("Hllo World!!!");
    return 0;
}
