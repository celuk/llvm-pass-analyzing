declare -a passarray=("-tti" "-targetlibinfo" "-assumption-cache-tracker" "-targetpassconfig" "-machinemoduleinfo" "-tbaa" "-scoped-noalias" "-profile-summary-info" "-collector-metadata" "-machine-branch-prob" "-domtree" "-basic-aa" "-aa" "-objc-arc-contract" "-pre-isel-intrinsic-lowering" "-atomic-expand" "-loops" "-loop-simplify" "-scalar-evolution" "-canon-freeze" "-iv-users" "-loop-reduce" "-mergeicmps" "-lazy-branch-prob" "-lazy-block-freq" "-expandmemcmp" "-gc-lowering" "-shadow-stack-gc-lowering" "-lower-constant-intrinsics" "-unreachableblockelim" "-postdomtree" "-branch-prob" "-block-freq" "-consthoist" "-partially-inline-libcalls" "-post-inline-ee-instrument" "-scalarize-masked-mem-intrin" "-expand-reductions" "-codegenprepare" "-rewrite-symbols" "-dwarfehprepare" "-safe-stack" "-stack-protector" "-amdgpu-isel" "-finalize-isel" "-lazy-machine-block-freq" "-early-tailduplication" "-opt-phis" "-slotindexes" "-stack-coloring" "-localstackalloc" "-dead-mi-elimination" "-machinedomtree" "-machine-loops" "-early-machinelicm" "-machine-block-freq" "-machine-cse" "-machinepostdomtree" "-machine-sink" "-peephole-opt" "-detect-dead-lanes" "-processimpdefs" "-unreachable-mbb-elimination" "-livevars" "-phi-node-elimination" "-twoaddressinstruction" "-liveintervals" "-simple-register-coalescing" "-rename-independent-subregs" "-machine-scheduler" "-livedebugvars" "-livestacks" "-virtregmap" "-liveregmatrix" "-edge-bundles" "-spill-code-placement" "-machine-opt-remark-emitter" "-greedy" "-virtregrewriter" "-stack-slot-coloring" "-machine-cp" "-machinelicm" "-fixup-statepoint-caller-saved" "-postra-machine-sink" "-shrink-wrap" "-prologepilog" "-branch-folder" "-tailduplication" "-postrapseudos" "-post-RA-sched" "-gc-analysis" "-block-placement" "-fentry-insert" "-xray-instrumentation" "-patchable-function" "-branch-relaxation" "-funclet-layout" "-stackmap-liveness" "-livedebugvalues" "-riscv-expand-pseudo" "-riscv-expand-atomic-pseudo")

for i in ${passarray[@]}; 
do 
cd ~/Desktop/tacle; 
# Location of your testbench files with .c extension, change ~/Desktop/tacle
~/riscv-new/_install/bin/clang --target=riscv32-unknown-elf -S -emit-llvm -Xclang -disable-O0-optnone -Xclang -disable-llvm-passes *.c; 
# Use your clang, change ~/riscv-new/_install/bin/clang  
# and if necessary use 
# --sysroot=/home/shc/riscv-new/_install/riscv64-unknown-elf --gcc-toolchain=/home/shc/riscv-new/_install/
# flags as --sysroot="{your-riscv-gnu-toolchain-install-or-build-path}/riscv64-unknown-elf" --gcc-toolchain="{your-riscv-gnu-toolchain-install-or-build-path}"
# More information here that I answered: https://stackoverflow.com/questions/68580399/using-clang-to-compile-for-risc-v
mkdir -p ~/tactr/$i && mv *.ll ~/tactr/$i; 
# Give an empty file location instead of both ~/tactr
cd ~/tactr/$i; for file in *.ll; 
# Give same file location above instead of ~/tactr
do 
echo ""; echo "${file##*/}"; echo "";
~/llvm/llvm-project/build/bin/opt -S $i "${file##*/}" -o "${file##*/}";
# Use your opt tool, change ~/llvm/llvm-project/build/bin/opt
done; 
clang-11 -S --target=riscv32-unknown-elf *.ll
# Use your clang, change clang-11 
done
