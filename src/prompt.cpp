#include <iostream>
#include <editline/readline.h>
#include <editline/history.h>

int main() {
    std::cout << "Lispy 1.0.0" << std::endl;

    while (char *input = readline("lispy> ")) {
        add_history(input);
        std::cout << input << std::endl;
    }

    return 0;
}

