// Copyright 2018 Romanov Alexander

#ifndef MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_CALC_COPY_H_
#define MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_CALC_COPY_H_

#include <string>

class QuadEquatCalc {
 public:
    QuadEquatCalc();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a;
        double b;
        double c;
        double root1;
        double root2;
    } Arguments;
};

#endif  // MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_CALC_COPY_H_