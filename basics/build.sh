cd "${0%/*}";

# Generate build system
cd ./build;
cmake -GNinja ..;

# Build executable
cmake --build .;  