
#include "python_eval.h"
#include <iostream>
using namespace std;

extern "C" {

    PythonBind* YaneuraOu() {
        return new PythonBind();
    }

    Value py_nnue_eval(PythonBind* pythonBind, std::string sfen) {
        return pythonBind->nnue_eval(sfen);
    }
}