# Python imports
import ctypes
import numpy as np

# Open shared CPP library:
soLib=ctypes.cdll.LoadLibrary('./naked_share.so')
yaneOu = soLib.YaneuraOu()
eval = soLib.py_nnue_eval

sfen = "l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1".encode('utf-8')
import time
start_time = time.time()
x = eval(yaneOu, ctypes.create_string_buffer(sfen))
print("--- %s seconds ---" % (time.time() - start_time))
print(x)

# soLib.string_test(ctypes.create_string_buffer(sfen))