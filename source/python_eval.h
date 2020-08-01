#pragma once
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include "misc.h"
#include <iostream>

class PythonBind {
public:
    PythonBind() {
        USI::init(Options);
        Bitboards::init();
        Position::init();
        Search::init();
        Threads.set(Options["Threads"]);
        Eval::init();
    }

    Value nnue_eval(std::string sfen) {
        Position pos;
        StateListPtr states(new StateList(1));
        pos.set(sfen, &states->back(), Threads.main());
        Value value = Eval::compute_eval(pos);
        Threads.set(0);
        return value;
    }
};

