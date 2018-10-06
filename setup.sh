string=$'#ifndef MESSAGE2SYNC_DATAPATH_H\n#define MESSAGE2SYNC_DATAPATH_H\n#include <iostream>\n\nstatic std::string filepath="'
string=$string`pwd`"/"
string=$string$'";\n\n#endif //MESSAGE2SYNC_DATAPATH_H'
echo "$string" > src/Kouhai/database/datapath.h
