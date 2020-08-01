
#include "python_eval.h"
#include <iostream>
#include <stdio.h>
using namespace std;

extern "C" {

    PythonBind* YaneuraOu() {
        return new PythonBind();
    }

    int py_nnue_eval(PythonBind* pythonBind, char sfen[]) {
        return pythonBind->nnue_eval(sfen);
    }

//    void string_test(char sfen[]) {
//        printf("sfen: %s\n", sfen);
//    }
}