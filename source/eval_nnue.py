# Python imports
import ctypes

# Open shared CPP library:
soLib=ctypes.cdll.LoadLibrary('./naked_share.so')
yaneOu = soLib.YaneuraOu()
eval = soLib.py_nnue_eval

import time
start_time = time.time()
sfen=ctypes.create_string_buffer("l6nl/5+P1gk/2np1S3/p1p4Pp/3P2Sp1/1PPb2P1P/P5GS1/R8/LN4bKL w GR5pnsg 1".encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('4k4/9/9/9/9/9/9/9/4K4 w R3P3p 1'.encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('4k4/9/9/9/9/9/9/9/4K4 b R3Pr3p 2'.encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('4k4/9/9/9/9/9/9/9/4K4 w R3Pr4p 3'.encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('4k4/9/9/4R4/9/9/9/9/4K4 b 4Pr4p 4'.encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('5k3/2r2s3/2l1p4/p2P2SNp/P3P1p1n/1p5G1/B8/2PGBp2+p/4K4 b RN 68'.encode('utf-8'))
print(eval(yaneOu, sfen))
sfen=ctypes.create_string_buffer('5k3/2r2s3/2l1p4/p2P2SNp/PB2P1p1n/1p5G1/B8/2PG1p2+p/4K4 w RN 69'.encode('utf-8'))
print(eval(yaneOu, sfen))
print("--- %s seconds ---" % (time.time() - start_time))
# soLib.string_test(ctypes.create_string_buffer(sfen))