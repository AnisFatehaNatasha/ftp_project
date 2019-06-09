#include"ftplib.h"
 
int main(void)
{
 
    netbuf *nbuf;
 
 int ftpCommand
    (
    int    ctrlSock, /* fd of control connection socket */
    char * fmt,      /* format string of command to send */
    int    arg1,     /* first of six args to format string */
    int    arg2,
    int    arg3,
    int    arg4,
    int    arg5,
    int    arg6
    )
  
  ftpCommand (ctrlSock, "TYPE I", 0, 0, 0, 0, 0, 0);     /* image-type xfer */
  ftpCommand (ctrlSock, "STOR %s", file, 0, 0, 0, 0, 0); /* init file write */
 
    FtpInit();
    FtpConnect("kernel.org", &nbuf);
    FtpLogin("anonymous", "", nbuf);
    FtpOptions(FTPLIB_CONNMODE, FTPLIB_PASSIVE, nbuf);
    FtpChdir("pub/linux/kernel", nbuf);
    FtpDir((void*)0, ".", nbuf);
    FtpGet("ftp.README", "README", FTPLIB_ASCII, nbuf);
    FtpQuit(nbuf);
 
    return 0;
}
 
