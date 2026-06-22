#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[]){
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    if(argc != 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments. Expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    
    FILE *f = fopen(writefile, "w");
    if(f == NULL)
    {
        syslog(LOG_ERR, "Failed to open file %s: %s", writefile, strerror(errno));
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    if(fputs(writestr, f) == EOF)
    {
        syslog(LOG_ERR, "Failed to write content to %s", writefile);
        fclose(f);
        closelog();
        return 1;
    }    
    fclose(f);
    closelog();

    return 0;
}
