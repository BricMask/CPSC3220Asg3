/* test driver */

#include "grtfs.h"

int main() {
  unsigned int fd[20];
  char buffer1[1024], buffer2[1024], buffer3[1024];
  unsigned int length1, length2, count1, count2, count3;

  sprintf( buffer1, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 64, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 128, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 192, "%s",
    "This is a simple-minded test for the trivial file system code.  " );
  sprintf( buffer1 + 256, "%s",
    "This is a simple-minded test for the trivial file system code.  " );

  sprintf( buffer2, "%s",
    "And now for something completely different." );

  length1 = strlen( buffer1 );
  length2 = strlen( buffer2 );
  printf( "length of buffer1 is %d\n", length1 );
  printf( "length of buffer2 is %d\n", length2 );

  grtfs_init();

  grtfs_list_directory();

  fd[0] = grtfs_create( "file.txt" );
  if( fd[0] == 0 ) printf( "first create failed\n" );

  fd[1] = grtfs_create( "my_file" );
  if( fd[1] == 0 ) printf( "second create failed\n" );

  grtfs_list_directory();

  count1 = grtfs_write( fd[0], buffer1, length1 );
  printf( "%d bytes written to first file\n", count1 );

  count2 = grtfs_write( fd[1], buffer2, length2 );
  printf( "%d bytes written to second file\n", count2 );

  count1 = grtfs_write( fd[0], buffer1, length1 );
  printf( "%d bytes written to first file\n", count1 );

  grtfs_list_directory();
  grtfs_list_blocks();

  grtfs_seek( fd[0], 600 );
  count3 = grtfs_read( fd[0], buffer3, 640 );
  printf( "%d bytes read from first file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_seek( fd[0], 250 );
  count3 = grtfs_read( fd[0], buffer3, 20 );
  printf( "%d bytes read from first file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  fd[2] = grtfs_create( "file.txt" );
  printf( "fd for creating a file with identical name" );
  printf( " as existing file - %d\n", fd[2] );
  fd[2] = grtfs_create( "file3" );
  fd[4] = grtfs_create( "file4" );
  fd[4] = grtfs_create( "file5" );
  fd[5] = grtfs_create( "file6" );
  fd[6] = grtfs_create( "file7" );
  fd[7] = grtfs_create( "file8" );
  fd[8] = grtfs_create( "file9" );
  fd[9] = grtfs_create( "file10" );
  fd[10] = grtfs_create( "file11" );
  fd[11] = grtfs_create( "file12" );
  fd[12] = grtfs_create( "file13" );
  fd[13] = grtfs_create( "file14" );
  fd[14] = grtfs_create( "file15" );
  fd[15] = grtfs_create( "file16" );
  printf( "fd for creating a sixteenth file - %d\n", fd[15] );

  grtfs_list_directory();

  grtfs_close( fd[0] );
  grtfs_delete( fd[0] );

  grtfs_list_directory();

  grtfs_close( fd[3] );
  grtfs_close( fd[4] );
  grtfs_close( fd[5] );
  grtfs_close( fd[6] );
  grtfs_close( fd[7] );

  grtfs_delete( fd[6] );
  grtfs_delete( fd[7] );

  grtfs_list_directory();

  fd[16] = grtfs_create( "added_1" );
  fd[17] = grtfs_create( "added_2" );

  grtfs_list_directory();
  grtfs_list_blocks();

  fd[18] = grtfs_create( "grtFile1" );
  fd[19] = grtfs_create( "grtFile2" );
  fd[20] = grtfs_create( "grtFile3" );
  fd[21] = grtfs_create( "grtFile4" );
  fd[22] = grtfs_create( "grtFile5" );
  fd[23] = grtfs_create( "grtFile6" );
  fd[24] = grtfs_create( "grtFile7" );
  fd[25] = grtfs_create( "grtFile8" );

  grtfs_list_directory();

  grtfs_close( fd[21] );
  grtfs_close( fd[22] );
  grtfs_close( fd[24] );

  grtfs_delete( fd[21] );
  grtfs_delete( fd[24] );

  grtfs_list_directory();

  fd[26] = grtfs_create( "newGrtFile1" );
  fd[27] = grtfs_create( "newGrtFile2" );
  fd[28] = grtfs_create( "newGrtFile3" );
  fd[29] = grtfs_create( "newGrtFile4" );
  fd[30] = grtfs_create( "newGrtFile5" );
  fd[31] = grtfs_create( "newGrtFile6" );

  grtfs_list_directory();

  count1 = grtfs_write( fd[25], buffer1, length1 );
  printf( "%d bytes written to file\n", count1 );

  count2 = grtfs_write( fd[25], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  count1 = grtfs_write( fd[31], buffer1, length1 );
  printf( "%d bytes written to file\n", count1 );

  grtfs_list_directory();

  fd[32] = grtfs_create( "endFile1" );
  fd[33] = grtfs_create( "endFile2" );
  fd[34] = grtfs_create( "endFile3" );
  fd[35] = grtfs_create( "endFile4" );
  
  grtfs_list_directory();

  count1 = grtfs_write( fd[35], buffer1, length1 );
  printf( "%d bytes written to file\n", count1 );

  count2 = grtfs_write( fd[34], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  count1 = grtfs_write( fd[35], buffer1, length1 );
  printf( "%d bytes written to file\n", count1 );

  grtfs_list_directory();

  count2 = grtfs_write( fd[32], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );
  count2 = grtfs_write( fd[32], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  count2 = grtfs_write( fd[33], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );
  count2 = grtfs_write( fd[33], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  count2 = grtfs_write( fd[34], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  count2 = grtfs_write( fd[31], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  grtfs_list_directory();
  grtfs_list_blocks();

  grtfs_close( fd[25] );
  grtfs_close( fd[33] );

  grtfs_delete( fd[25] );
  grtfs_delete( fd[33] );
  
  grtfs_list_directory();
  grtfs_list_blocks();

  grtfs_close( fd[34] );
  grtfs_delete( fd[34] );

  fd[36] = grtfs_create( "testFile1" );
  fd[37] = grtfs_create( "testFile2" );
  fd[38] = grtfs_create( "deleteWriteFile" );
  count2 = grtfs_write( fd[38], buffer1, length1 );
  printf( "%d bytes written to file\n", count1 );

  grtfs_list_directory();

  grtfs_seek( fd[1], 10 );
  count3 = grtfs_read( fd[1], buffer3, 20 );
  printf( "%d bytes read from file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_seek( fd[1], 20 );
  count3 = grtfs_read( fd[1], buffer3, 5 );
  printf( "%d bytes read from file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_close( fd[1] );

  grtfs_seek( fd[32], 1 );
  count3 = grtfs_read( fd[32], buffer3, 42 );
  printf( "%d bytes read from file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  count2 = grtfs_write( fd[30], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );
  count2 = grtfs_write( fd[30], buffer2, length2 );
  printf( "%d bytes written to file\n", count2 );

  grtfs_seek( fd[30], 30 );
  count3 = grtfs_read( fd[30], buffer3, 25 );
  printf( "%d bytes read from file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_seek( fd[31], 320 );
  count3 = grtfs_read( fd[31], buffer3, 42 );
  printf( "%d bytes read from file\n", count3 );
  buffer3[count3] = '\0';
  printf( "[%s]\n", buffer3 );

  grtfs_close( fd[31] );

  grtfs_list_directory();

  grtfs_close( fd[38] );
  grtfs_close( fd[35] );

  grtfs_delete( fd[38] );
  grtfs_delete( fd[35] );

  grtfs_list_directory();
  grtfs_list_blocks();

  return 0;
}