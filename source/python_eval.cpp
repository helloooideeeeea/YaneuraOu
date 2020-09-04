#pragma once
#include "python_eval.h"
#include <iostream>
#include <stdio.h>
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include "misc.h"

using namespace std;

PythonBind::PythonBind() {
    USI::init(Options);
    Bitboards::init();
    Position::init();
    Search::init();
    Threads.set(Options["Threads"]);
    Eval::init();
}

int PythonBind::nnue_eval(std::string sfen) {
    Position pos;
    StateListPtr states(new StateList(1));
    pos.set(sfen, &states->back(), Threads.main());
    return static_cast<int>(Eval::compute_eval(pos));
}

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