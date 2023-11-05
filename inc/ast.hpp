# pragma once

# include "tokenization.hpp"

struct ast {
    int           val;
    Token         token;
    struct ast* left;
    struct ast* right;

//      <left> <right> <Token> <val>
    ast(ast* _left, ast* _right, Token _token, int _val) : 
        val(_val) , token(_token), left(_left), right(_right) {}
};

class Parser {
    tokenization* token;
    Itr it;

    public:
        Parser(tokenization*_tokens) : token(_tokens) {
            if (_tokens)
                it = token->begin();
        }
        ast*   parser();
        void   scanToken();
        Token  currToken();

    private:
        ast* expression() ;
        ast* term();
        ast* factor();
        ast* unary_expression();
        ast* primary();
};

#define heap Mgr.insertAddress

