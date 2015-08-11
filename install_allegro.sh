apt-get update
apt-get install build-essential git cmake cmake-curses-gui xorg-dev libgl1-mesa-dev libglu-dev
apt-get install libpng-dev libcurl4-openssl-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev \
 libgtk2.0-dev libasound-dev libpulse-dev libflac-dev libdumb1-dev
cd ../
git clone https://github.com/liballeg/allegro5.git
cd allegro5
git checkout 5.0
ccmake -DCMAKE_INSTALL_PREFIX=/usr ./
make
make install
