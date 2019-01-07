#include <iostream>
#include <editline/readline.h>
#include <editline/history.h>
#include <mpc.h>

int main() {
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT, R"(
    number   : /-?[0-9]+/ ;
    operator : '+' | '-' | '*' | '/' ;
    expr     : <number> | '(' <operator> <expr>+ ')' ;
    lispy    : /^/ <operator> <expr>+ /$/ ;
    )",
    Number, Operator, Expr, Lispy);

    std::cout << "Lispy 1.0.0" << std::endl;

    while (char *input = readline("lispy> ")) {
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            mpc_ast_print(static_cast<mpc_ast_t*>(r.output));
            mpc_ast_delete(static_cast<mpc_ast_t*>(r.output));
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
    }

    mpc_cleanup(4, Number, Operator, Expr, Lispy);
    return 0;
}

