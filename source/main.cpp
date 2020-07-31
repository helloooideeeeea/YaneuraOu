
//#include "bitboard.h"
//#include "position.h"
#include "search.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include "misc.h"
#include <iostream>

// ----------------------------------------
//  main()
// ----------------------------------------

int main(int argc, char* argv[])
{
	// --- 全体的な初期化

	Misc::init(argv);
	USI::init(Options);
	Bitboards::init();
	Position::init();
	Search::init();
	Threads.set(Options["Threads"]);
	//Search::clear();
	Eval::init();

	Position pos;
	// 局面を遡るためのStateInfoのlist。
	StateListPtr states(new StateList(1));
	pos.set("l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1", &states->back(), Threads.main());
	std::cout << "eval = " << Eval::compute_eval(pos) << std::endl;
	// 生成して、待機させていたスレッドの停止
	Threads.set(0);


	return 0;
}
