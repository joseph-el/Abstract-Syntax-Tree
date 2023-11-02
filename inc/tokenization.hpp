# pragma once

#include <sstream>
#include <set>

#include "manageHeap.hpp"

#define UNEXPECTED "syntax error near unexpected token "
#define TOK (*token)


# define V_LPAR_LEFT  (BEGIN)

# define V_LPAR_RIGHT (4)



# define V_RPAR_LEFT  (8)
# define V_RPAR_RIGHT (16)


# define V_DIGIT_LEFT (1)
# define V_DIGIT_RIGHT (1)

# define OPT (Division | Factorial)

enum Token {
    LPAR = (1<<1),
    RPAR = (1<<2),
    DIGIT = (1<<3),
    WSPACE = (1<<4),
    UNKNOWN = (1<<5),

    DIV = (1 << 6),
    ADD = (1 << 7),
    MOD = (1 << 8),
    SUB = (1 << 10),
    MUL = (1 << 11),
    POW = (1 << 12),
    FAC = (1 << 8),
    
    BEGIN          = (1<<13),
    END            = (1<<14),
};



class tokenization : public deque< pair<int, Token> > {
    public:
        
        tokenization() {
            push_back(make_pair(-1, BEGIN));
        }
        typedef deque< pair<int, Token>>::iterator Itr;
        void adding(pair<int, Token>&);
        Token getToken(const char &);
        int  consumeNumbers(stringstream&, Token ret = DIGIT);
        void consumeWspace(stringstream&, Token ret = WSPACE);
        void getBack(stringstream&);
        int FindToken(Itr , bool);

        bool syntax();

        bool unexpectedSyntax();
        bool parenthesesSyntax(Itr &);
        bool digitSyntax(Itr &);
        bool binarySyntax(Itr &);
        bool unarySyntax(Itr &);


        void error(const char *, const char );
        void printTokens();
};

tokenization* lexer(stringstream &prompt);
