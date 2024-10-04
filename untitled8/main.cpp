#include <iostream>
#include <utility>

using namespace std;

class Number;

class Expression{
private:
    string expression;
    //int str{};
    //Expression b();
public:
    //Expression(){}


    virtual string print() = 0;

    virtual Expression *derivative() = 0;

    virtual Expression *stringExpression() = 0;

    //virtual Expression *converter(const string &str, const string &operate = "") = 0;

    operator 
};



class Number : public Expression{
private:
    int number;
public:
    explicit Number(int a) : number(a){}
    string print() override{
        return to_string(number);
    }
    Expression *stringExpression() override{
        return new Number(number);
    }
    Expression *derivative() override{
        return new Number(0);
    }

};

class Variable : public Expression{
private:
    string str;
public:
    explicit Variable(string symbol) : str(std::move(symbol)){}
    string print() override{
        return str;
    }
    Expression *stringExpression() override{
        return new Variable(str);
    }
    Expression *derivative() override{
        return new Variable("1");
    }
};

class Add : public Expression{
private:
    Expression *exp1, *exp2;
public:

    Add(Expression *a,Expression *b) : exp1(a), exp2(b){}

    string print() override{
        return "(" + exp1->print() + "+" + exp2->print() + ")";
    }
    Expression *stringExpression() override{
        return new Add{exp1, exp2};
    }
    Expression *derivative() override{
        return new Add{exp1->derivative(), exp2->derivative()};
    }
};

class Sub : public Expression{
private:
    Expression *exp1, *exp2;
public:
    Sub(Expression *a,Expression *b) : exp1(a), exp2(b) {}

    string print() override{
        return "(" + exp1->print() + "-" + exp2->print() + ")";
    }
    Expression *stringExpression() override{
        return new Sub(exp1, exp2);
    }
    Expression *derivative() override{
        return new Sub{exp1->derivative(), exp2->derivative()};
    }
};

class Mul : public Expression{
private:
    Expression *exp1, *exp2;
public:
    Mul(Expression *a, Expression *b) : exp1(a), exp2(b) {}

    string print() override{
        return "(" + exp1->print() + "*" + exp2->print() + ")";
    }
    Expression *stringExpression() override{
        return new Mul(exp1, exp2);
    }
    Expression *derivative() override{
        return new Add{
            new Mul{exp1->derivative(), exp2->stringExpression()},
            new Mul{exp1->stringExpression(), exp2->derivative()}
        };
    }
//    Expression * converter(const string &str, const string &operate = "") override{
//        string left, right, operateExp;
//        // тута скобачки, да плюсики с минусиками
//        //
//        return new Mul{converter(left, operateExp), converter(right,operateExp)};
//    }
};

class Div : public Expression{
private:
    Expression *exp1, *exp2;
public:
    Div(Expression *a,Expression *b) : exp1(a), exp2(b) {}

    string print() override{
        return "(" + exp1->print() + "/" + exp2->print() + ")";
    }
    Expression *stringExpression() override{
        return new Div{exp1, exp2};
    }
    Expression *derivative() override{
        return new Div{
            new Sub{
                new Mul{exp1->derivative(), exp2->stringExpression()},
                new Mul{exp1->stringExpression(), exp2->derivative()}
                },
            new Mul{exp1->stringExpression(), exp2->stringExpression()}
        };
    }
};

//class Converter : public Number, public Variable, public {
//
//};



//Expression GGG(const string& str){
//
//    string left,right, operatorExp;
//    // тута скобачки и операции
//
//
//
//
//
//    return new
//}




int main() {
    //int a;

    // Realise other operation
    // eval - solve expression relatively variable
    // dynamic memory WARNING !
    // derivative for several str variables


//    Expression *b = new Add{
//        new Number{3},
//        new Mul{
//            new Number{2},
//            new Variable{"x"}
//        }
//    };

//    cout << b->print() << endl;
//    Expression *nn = b->derivative();
//    cout << nn->print();




    return 0;
}
