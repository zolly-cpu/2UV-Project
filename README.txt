Compile with the following:
---------------------------
zeroc
- sudo apt install zeroc*
- sudo apt install libzeroc*
postgresql
- sudo apt install postgres*
qt5
- sudo apt install libqt5*
scons
- python3 -m pip install scons==4.2.0
---------------------------
sudo apt install pip
mv /usr/lib/python3.13/EXTERNALLY-MANAGED /home/zolly/Documents
python3 -m pip install scons==4.2.0



sudo -u postgres createuser --login --pwprompt wolly
passw: wolly
sudo -u postgres dropdb TEST_PROJECT
sudo -u postgres createdb --owner=wolly TEST_PROJECT
psql TEST_PROJECT
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

And then update with DatabaseEditor

The startup arguments for the applications you can find in the AppStarter.xml

In the ObjectViewer
- Planning nog finisched yet
- Location tracking objects must be created in the ServerTest

SocketBox
- Open for imlplementing dll's with the protocoll for communication
