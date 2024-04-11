#include "grtfs.h"


/* implementation of assigned functions */


/* you are welcome to use helper functions of your own */



/* tfs_delete()
 *
 * deletes a closed directory entry having the given file descriptor
 *   (changes the status of the entry to unused) and releases all
 *   allocated file blocks
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is closed
 *
 * postconditions:
 *   (1) the status of the directory entry is set to unused
 *   (2) all file blocks have been set to free
 *
 * input parameter is a file descriptor
 *
 * return value is TRUE when successful or FALSE when failure
 */

unsigned int grtfs_delete( unsigned int file_descriptor ){
  if (grtfs_check_fd_in_range( file_descriptor )) {
    return FALSE;
  }
  if (directory[file_descriptor].status == CLOSED) {
    return FALSE;
  }

  directory[file_descriptor].status = UNUSED;
  
  unsigned char first_block = directory[file_descriptor].first_block;
  for (int i = 0; i < directory[file_descriptor].size; ++i) {
    unsigned char current_block = first_block+i;
    file_allocation_table[current_block] = FREE;
  }

  return TRUE;
}


/* tfs_read()
 *
 * reads a specified number of bytes from a file starting
 *   at the byte offset in the directory into the specified
 *   buffer; the byte offset in the directory entry is
 *   incremented by the number of bytes transferred
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * the function will read fewer bytes than specified if the
 *   end of the file is encountered before the specified number
 *   of bytes have been transferred
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *   (3) the file has allocated file blocks
 *
 * postconditions:
 *   (1) the buffer contains bytes transferred from file blocks
 *   (2) the specified number of bytes has been transferred
 *         except in the case that end of file was encountered
 *         before the transfer was complete
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 */

unsigned int grtfs_read( unsigned int file_descriptor,
                       char *buffer,
                       unsigned int byte_count ){

  if (grtfs_check_fd_in_range( file_descriptor )) {
    return FALSE;
  }
  if ( grtfs_check_file_is_open( file_descriptor ) ) {
    return FALSE;
  }

  unsigned short byte_offset = directory[file_descriptor].byte_offset;
  unsigned int bytes_transferred = 0;

    while (bytes_transferred < byte_count) {
        for (int i = 0; i < BLOCK_SIZE; ++i) {

            char b = blocks[directory[file_descriptor].first_block].bytes[byte_offset];
            byte_offset++;

            if (byte_offset >= directory[file_descriptor].size) {
            return bytes_transferred;
            } //end of file
            buffer[i] = b;
            bytes_transferred++;

            if (bytes_transferred >= byte_count) {
                return bytes_transferred;
            }
        }

    }

  return bytes_transferred;

}

/* tfs_write()
 *
 * writes a specified number of bytes from a specified buffer
 *   into a file starting at the byte offset in the directory;
 *   the byte offset in the directory entry is incremented by
 *   the number of bytes transferred
 *
 * depending on the starting byte offset and the specified
 *   number of bytes to transfer, the transfer may cross two
 *   or more file blocks
 *
 * furthermore, depending on the starting byte offset and the
 *   specified number of bytes to transfer, additional file
 *   blocks, if available, will be added to the file as needed;
 *   in this case, the size of the file will be adjusted
 *   based on the number of bytes transferred beyond the
 *   original size of the file
 *
 * the function will read fewer bytes than specified if file
 *   blocks are not available
 *
 * preconditions:
 *   (1) the file descriptor is in range
 *   (2) the directory entry is open
 *
 * postconditions:
 *   (1) the file contains bytes transferred from the buffer
 *   (2) the specified number of bytes has been transferred
 *         except in the case that file blocks needed to
 *         complete the transfer were not available
 *   (3) the size of the file is increased as appropriate
 *         when transferred bytes extend beyond the previous
 *         end of the file
 *
 * input parameters are a file descriptor, the address of a
 *   buffer of bytes to transfer, and the count of bytes to
 *   transfer
 *
 * return value is the number of bytes transferred
 */

unsigned int grtfs_write( unsigned int file_descriptor,
                        char *buffer,
                        unsigned int byte_count ){

  if( grtfs_check_fd_in_range( file_descriptor ) ) {
    if( grtfs_check_file_is_open( file_descriptor ) ) {
      for (int i = 0; i < byte_count; ++i) {
         = buffer[i];
      }
    }
  }
}

bool file_is_readable() {

}

bool file_is_writable() {

}

void make_readable() {

}

void make_writable() {
  
}