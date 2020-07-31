
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include "misc.h"
#include <iostream>
using namespace std;

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

    Value eval(std::string sfen) {
        Position pos;
        StateListPtr states(new StateList(1));
        pos.set(sfen, &states->back(), Threads.main());
        return Eval::compute_eval(pos);
    }
};

extern "C" {

    PythonBind* YaneuraOu() {
        return new PythonBind();
    }

    Value nnue_eval(PythonBind* pythonBind, std::string sfen) {
        return pythonBind->eval(sfen);
    }
}