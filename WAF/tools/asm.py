import waflib.Tools.asm
import waflib.Task

# Redefine asm class:
# make sure that the assembler also passed the C-Defines, as we are using gcc as assembler
# which may include .h files with #ifdef
class asm(waflib.Task.Task):
    color = 'NORMAL'
    run_str = '${AS} ${ASFLAGS} ${CPPPATH_ST:INCPATHS} ${DEFINES_ST:DEFINES} ${AS_SRC_F}${SRC} ${AS_TGT_F}${TGT}'
