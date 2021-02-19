# Libvector
## A vector library for C.
[![build](https://github.com/s-t-a-n/libvector/workflows/Unittests/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=Unittests)
[![linux](https://github.com/s-t-a-n/libvector/workflows/Linux/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=Linux)
[![macos](https://github.com/s-t-a-n/libvector/workflows/MacOS/badge.svg)](https://github.com/s-t-a-n/libvector/actions?workflow=MacOS)

### Notes

- using V_FIND_NTH or V_FIND_NTH_REV could have undefined consequences since a void ptr is casted to a function pointer, which on some systems do not have the same size.
