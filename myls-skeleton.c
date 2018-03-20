#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>

int
main(int argc, char **argv) {
    DIR *dir;
    struct dirent *file;
    struct stat filestat;
    struct passwd *owner;

    if (argc > 2) {
        fprintf(stdout, "Usage: myls [FILE]");
        exit(-1);
    }



    if (argc == 1) {
        //TODO if no directory is supplied by calling user,
        //     then just open current directory
       if(argv[argc]==NULL){
      dir = opendir(".");
   }

       
    } else {
        //TODO open the directory supplied by the user
        //     Hint: argv is an array populated with calling 
        //     user arguments
       dir= opendir(argv[0]);
    }

    if (!dir) {
        //TODO Error check throw error if failure upon opening a directory
        printf("Error opening directory\n");
                exit(0);

    }

     while ((file=readdir(dir)) != NULL) {

                stat(file->d_name, &filestat);    
                owner = getpwuid(filestat.st_uid);
                printf("%s\t", owner->pw_name);
                printf("%ld\t",filestat.st_size);
                printf(" %s\t", file->d_name);
                printf("\n");
        }

    
    closedir(dir);
    
    //TODO Loop while there are still files within the directory
    //     to be read
    //
    //     BEGIN LOOP:
    //     TODO: Get the metadata and user information of the current file
    //     TODO: Print this data
    //     END LOOP

    //TODO: Close the opened directory

    return 0;
}
