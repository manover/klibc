/*
 * sleep.c
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <linux/times.h>

unsigned int sleep(unsigned int seconds)
{
  struct timespec ts;

  ts.tv_sec = seconds;
  ts.tv_nsec = 0;
  if ( !nanosleep(&ts,&ts) )
    return 0;
  else if ( errno == EINTR )
    return ts.tv_sec;
  else
    return -1;
}
