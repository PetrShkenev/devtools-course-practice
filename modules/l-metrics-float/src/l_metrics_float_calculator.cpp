// Copyright 2018 Galochkin Boris

#include <vector>
#include <string>

#include "include/l_metrics_float_calculator.h"

LMetricsFloatCalculator::LMetricsFloatCalculator() {
}

std::string LMetricsFloatCalculator::operator()(int argc, const char ** argv) {
    Arguments args;
    parseArguments(argc, argv, &args);
    return message_;
}

void LMetricsFloatCalculator::help(const char * appname, const char * message) {
    message_ = std::string(message) +
        "Please provide arguments in the following format:\n\n"

        "$ " + appname + " <distance type>\n"
        "<first vector length = n> <v1[0]> <v1[1]> ... <v1[n]>\n"
        "<second vector length = n> <v2[0]> <v2[1]> ... <v2[n]>\n\n"

        "Where <length> are integer, vectors values are float numbers, "
        "and <distance type> is one of 'Linf', 'L1', 'L2', 'L3', 'L4'\n";
}

bool LMetricsFloatCalculator::parseArguments(int argc, const char ** argv, Arguments* out_args) {
    if (argc < 5) {
        help(argv[0]);
        return false;
    }
    auto mode = std::string(argv[1]);
    if (mode == "Linf") {
        out_args->mode = Mode::Linf;
    } else if (mode == "L1") {
        out_args->mode = Mode::L1;
    } else if (mode == "L2") {
        out_args->mode = Mode::L2;
    } else if (mode == "L3") {
        out_args->mode = Mode::L3;
    } else if (mode == "L4") {
        out_args->mode = Mode::L4;
    } else {
        help(argv[0]);
        return false;
    }
    try {
        int v1_len = std::stoi(argv[2]);
        if (argc < v1_len + 4) {
            help(argv[0]);
            return false;
        }
        int v2_len = std::stoi(argv[3 + v1_len]);
        if (argc < v1_len + 4 + v2_len) {
            help(argv[0]);
            return false;
        }
        for (size_t i = 3; i < v1_len + 3; i++)
            out_args->vec1.emplace_back(std::stof(argv[i]));
        for (size_t i = v1_len + 4; i < v1_len + 4 + v2_len; i++)
            out_args->vec1.emplace_back(std::stof(argv[i]));
    }
    catch (std::invalid_argument&) {
        help(argv[0]);
        return false;
    }
    return true;
}
