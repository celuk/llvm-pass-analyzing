# llvm-pass-analyzing

YOU SHOULD CHANGE FILE LOCATIONS ON YOUR OWN AS STATED ON THE SCRIPTS

On Linux:
If you want to generate llvm pass performed assembly files for every .c code use generatefilesandperformpasses bash script.

After this, there should be sub folders for every passes that include pass performed assembly files.
These are here as prepared files: https://drive.google.com/drive/folders/1WF6mEyKOX2Y1FMkxhLRCBE3myN1R6Ltk?usp=sharing

You can perform countopcodessaveastexts bash script at this folder but also counted opcodes are ready in sub folders as ac.txts

On Windows:
You can perform generatexlfromtexts.py to generate Excel file from ac.txts
Generated Excel file is here: https://docs.google.com/spreadsheets/d/10ycsNMaOO5hd7FX9r2K0taCoYTO8YBPf/edit?usp=sharing&ouid=111846633649891187648&rtpof=true&sd=true

You can perform generategraphsfromxl.py to generate bar charts from this Excel file

For python scripts you should install these packages:

pip install pandas
pip install matplotlib
pip install numpy
pip install openpyxl

Performing llvm pass operations you should clone and build llvm library as:

# For cmake and ninja
sudo snap install cmake --classic

sudo apt install ninja-build

# For llvm library
git clone https://github.com/llvm/llvm-project.git && cd llvm-project && mkdir build && cd build && cmake -G Ninja -DLLVM_ENABLE_PROJECTS=clang -DLLVM_TARGETS_TO_BUILD=all -DLLVM_ENABLE_LIBCXX=ON -DCMAKE_BUILD_TYPE=Release -DLLVM_INSTALL_UTILS=ON -DBUILD_SHARED_LIBS=True -DLLVM_USE_SPLIT_DWARF=True -DLLVM_OPTIMIZED_TABLEGEN=True -DLLVM_BUILD_TESTS=True -DLLVM_PARALLEL_LINK_JOBS=1 ../llvm && cmake --build .

Just you need to copy and paste above command to terminal it can take too much time.

After built, for llvm file locations you can find executables in bin folder like /home/shc/llvm/llvm-project/build/bin/clang, /home/shc/llvm/llvm-project/build/bin/opt
