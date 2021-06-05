#include<jni.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "HelloJNI.h"

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello Akash!\n");
   struct stat stats;

      if (stat("C:/Users/akash/Downloads/Final Report.docx", &stats) == 0) {
           struct tm dt;

                if( S_ISREG(stats.st_mode) )
                    printf("Regular file");
               else
                   printf("Not a regular file");

               printf("\nOwner permissions: ");
               if( stats.st_mode & S_IRUSR )
                   printf("read ");
               if( stats.st_mode & S_IWUSR )
                   printf("write ");
               if( stats.st_mode & S_IXUSR )
                   printf("execute");
               printf("\n");

               printf("Group permissions: ");
               if( stats.st_mode & S_IRGRP )
                   printf("read ");
               if( stats.st_mode & S_IWGRP )
                   printf("write ");
               if( stats.st_mode & S_IXGRP )
                   printf("execute");
               printf("\n");

               printf("Others permissions: ");
               if( stats.st_mode & S_IROTH )
                   printf("read ");
               if( stats.st_mode & S_IWOTH )
                   printf("write ");
               if( stats.st_mode & S_IXOTH )
                   printf("execute");
               printf("\n");

               printf("\nFile access: ");
               if (stats.st_mode & R_OK)
                   printf("read ");
               if (stats.st_mode & W_OK)
                   printf("write ");
               if (stats.st_mode & X_OK)
                   printf("execute");
               printf("\nFile size: %d", stats.st_size);

               dt = *(gmtime(&stats.st_ctime));
               printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900,
                                                         dt.tm_hour, dt.tm_min, dt.tm_sec);

               dt = *(gmtime(&stats.st_mtime));
               printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900,
                                                         dt.tm_hour, dt.tm_min, dt.tm_sec);

               printf("%10.10s", stats.st_mode);
               printf("%4d", stats.st_nlink);


      }
   return;
}