git clone https://github.com/jordanvrtanoski/luacpp.git
cd luacpp
mkdir build
cd build
cmake ../Source
make -k `nproc`
make install