# Test with EMCC

## Setup build environment

```shell
mkdir build_emcc
cd build_emcc
source ~/workspace/github/emsdk/emsdk_env.sh
```

## Test sanitizer

```shell
emcmake cmake -DENABLE_SANITIZE=1 -DCMAKE_BUILD_TYPE=Debug ..
make -j $(nproc)
node test/TestMyLib.js --  --gtest_filter=TestMyLib.TestGoo
```

Got error

```shell
==42==ERROR: AddressSanitizer: heap-use-after-free on address 0x020002b0 at pc 0x0001f8b1 bp 0x00ee3400 sp 0x00ee340c
WRITE of size 4 at 0x020002b0 thread T0
    #0 0x1f8b1 in MyLib::goo()+0x1f8b1 (data:application/octet-stream;base64,AGFzbQEAAAABjwVUYAF/AX9gAn9/AX9gAn9/AGABfwBgA39/fwF/YAAAYAN/f38AYAR/f39/AGAEf39/fwF/YAABf2AGf39/f39/AX9gBX9/f39/AX9gBX9/f39/AGAGf39/f39/AGAIf39/f39/f38Bf2ABfwF+YAJ/fwF+YAABfmAHf39/f39/fwBgB39/f39/f38Bf2ACf34AYAN/fn8Bfm+0x1f8b1)
```

## Use ctest

```shell
ctest --output-on-failure
```
