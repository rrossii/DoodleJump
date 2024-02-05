# SDL2_image
sudo apt-get install libsdl2-image-dev

# SDL2
mkdir $HOME/doodle
cd $HOME/doodle
git clone https://github.com/libsdl-org/SDL.git -b SDL2
cd SDL
mkdir build
cd build
../configure
make
sudo make install