# Python imports
import ctypes
import numpy as np

# Open shared CPP library:
soLib=ctypes.cdll.LoadLibrary('./naked_share.so')
yaneOu = soLib.YaneuraOu()
eval = soLib.py_nnue_eval

sfen = "l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1".encode('utf-8')
x = eval(yaneOu, ctypes.create_string_buffer(sfen))
print(x)

# str = "l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1"
# b_string = str.encode('utf-8')
# soLib.string_test(ctypes.create_string_buffer(b_string))