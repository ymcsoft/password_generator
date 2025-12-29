#include <iostream>
#include <string>
#include "random_generator.h"
#include "CLI11.hpp"

int main(int argc, char *argv[]) {
    CLI::App app{"Password Generator"};

    int length = 15;
    bool useUpper = false, useLower = false, useDigits = false, useSpecial = false;

    app.add_option("-n,--length", length, "Number of characters in the password")
            ->default_val(15);
    app.add_flag("-U,--uppercase", useUpper, "Include uppercase letters")
            ->default_val(false);
    app.add_flag("-l,--lowercase", useLower, "Include lowercase letters")
            ->default_val(false);
    app.add_flag("-d,--digits", useDigits, "Include digits")
            ->default_val(false);
    app.add_flag("-s,--special", useSpecial, "Include special symbols")
            ->default_val(false);

    CLI11_PARSE(app, argc, argv);

    if (!useUpper && !useLower && !useDigits && !useSpecial) {
        useUpper = useLower = useDigits = useSpecial = true;
    }

    std::cout << "\nGenerated random string: " << generateRandomString(length, useUpper, useLower, useDigits,
                                                                       useSpecial) << std::endl;

    return 0;
}
