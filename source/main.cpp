#include "python_eval.h"
#include "thread.h"
#include "tt.h"
#include "usi.h"
#include <iostream>

// ----------------------------------------
//  main()
// ----------------------------------------

int main(int argc, char* argv[])
{
	// --- 全体的な初期化

	PythonBind *py = new PythonBind;
	int v = py->nnue_eval("l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1");
	std::cout << "eval = " << v << std::endl;
	delete py;

	return 0;
}
