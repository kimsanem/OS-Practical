#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char*argv[]){
    int i;
    struct stat s;
    if(argc < 2){
        cout << "\n Enter file name: ";
        exit(0);
    }
    for(i=1; i<argc; i++){
        cout << "File: " << argv[i] << "\n";
        if(stat(argv[i], &s) < 0){
            cout << "error in obtaining stats \n";
        }else{
            cout << "Owner UID: "; cout << s.st_uid;
            cout << "\n group id: "; cout << s.st_gid;
            cout << "\n access permissoion: "; cout << s.st_mode;
            cout << "\n access time: "; cout << s.st_atime;
            cout << "\n file size: "; cout << s.st_size;
            cout << "\n file size(in blocks): "; cout << s.st_blksize << endl;
        }
    }
    return 0;
}
