#ifndef VISITOR_H
#define VISITOR_H
#include "ast.h"
#include <list>
#include <unordered_map>
#include "environment.h"

class BinaryExp;
class NumberExp;
class SqrtExp;

class Visitor {
public:
    virtual int visit(BinaryExp* exp) = 0;
    virtual int visit(NumberExp* exp) = 0;
    virtual int visit(IdExp* exp) = 0;
    virtual int visit(SqrtExp* exp) = 0;
    virtual void visit(AsignStmt* stm) = 0;
    virtual void visit(PrintStmt* stm) = 0;
    virtual void visit(IfStmt* stm) = 0;
    virtual void visit(WhileStmt* stm) = 0; 
    virtual void visit(VarDec* stm) = 0; 
    virtual void visit(Body* stm) = 0; 
    virtual void visit(Programa* program) = 0;
    virtual bool visit(CBinaryExp* exp) =0;
};

class PrintVisitor : public Visitor {
public:

    int visit(BinaryExp* exp) override;
    int visit(NumberExp* exp) override;
    int visit(SqrtExp* exp) override;
    void visit(AsignStmt* stm) override;
    void visit(PrintStmt* stm) override;
    void visit(Programa* program) override;
    int visit(IdExp* exp) override;
    void visit(IfStmt* stm) override; 
    void visit(WhileStmt* stm) override;
    void visit(VarDec* stm) override; 
    void visit(Body* b) ;   
    void imprimir(Programa* program);
};

class EVALVisitor : public Visitor {
public:
    Environment<int> memoria;
    int visit(BinaryExp* exp) override;
    int visit(NumberExp* exp) override;
    int visit(SqrtExp* exp) override;
    void visit(AsignStmt* stm) override;
    void visit(PrintStmt* stm) override;
    int visit(IdExp* exp) override;
    void visit(IfStmt* stm) override; 
    void visit(WhileStmt* stm) override; 
    void visit(Programa* program) override;
    void visit(VarDec* stm) override;  
    void visit(Body* b) ;  
    void interprete(Programa* program);
};


#endif // VISITOR_H