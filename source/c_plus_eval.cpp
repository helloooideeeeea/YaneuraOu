#pragma once
#include "c_plus_eval.h"
#include <iostream>
#include <stdio.h>
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include "misc.h"

using namespace std;

CPlusBind::CPlusBind() {
    USI::init(Options);
    Bitboards::init();
    Position::init();
    Search::init();
    Threads.set(Options["Threads"]);
    Eval::init();
}

int CPlusBind::nnue_eval(std::string sfen) {
    Position pos;
    StateListPtr states(new StateList(1));
    pos.set(sfen, &states->back(), Threads.main());
    return static_cast<int>(Eval::compute_eval(pos));
}
