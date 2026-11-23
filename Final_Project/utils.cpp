
#include "utils.h"

namespace Utils {

    // ANSI escape sequence
    const std::string RESET = "\033[0m";

    void clearScreen() {

        #ifdef _WIN32
            // Enable ANSI escape sequence support on Windows
            // Windows 10 and later support virtual terminal processing.
            std::cout << "\033[2J\033[H";
        #else
            std::cout << "\033[2J\033[H";
        #endif

        std::cout.flush();
    }

    void resetColor() {
        std::cout << RESET;
        setBackground(Background::BLACK);
        setColor(Color::BRIGHT_WHITE);
    }

    void setColor(Color color) {
        std::cout << "\033[" << static_cast<int>(color) << "m";
    }

    void setBackground(Background background) {
        std::cout << "\033["
                  << static_cast<int>(background)
                  << "m";
    }

    void printSeparator(char character, int width) {
        std::cout << std::string(width, character) << '\n';
    }

    void printHeader(const std::string& title) {

        std::cout << '\n';

        setColor(Color::BRIGHT_CYAN);
        printSeparator('=');

        setColor(Color::BRIGHT_WHITE);
        std::cout << "  " << title << '\n';

        setColor(Color::BRIGHT_CYAN);
        printSeparator('=');

        resetColor();
        std::cout << '\n';
    }

}
