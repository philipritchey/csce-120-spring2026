#include <iostream>
#include <string>
#include <cassert>

// replace all vowels in the input string with "#"
std::string replace_vowels(std::string str) {
    // TODO(student)
    // find the position of the first vowel
    size_t index_of_vowel = str.find_first_of("aeiou");
    // while a vowel was found
    while (index_of_vowel != std::string::npos) {
        // replace the vowel with "#"
        str.replace(index_of_vowel, 1, "#");
        // find the position of the next vowel
        index_of_vowel = str.find_first_of("aeiou");
    }  // end-while
    return str;
}

// prompt the user for input
// return a string containing the user's response
std::string input(std::string prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {
    // std::string line = input("Enter a line of text:\n");
    // std::string line_no_vowels = replace_vowels(line);
    // std::cout << line_no_vowels << std::endl;

    assert(replace_vowels("apple") == "#ppl#");
    std::cout << replace_vowels("juice") << std::endl;
    assert(replace_vowels("juice") == "j##c#");

    return 0;
}
