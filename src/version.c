#include <stdio.h>

#include "version.h"

// print full magic player version information 
void magic_player_version_print_full (void) {

    printf ("\nMagic Player Version: %s\n", MAGIC_PLAYER_VERSION_NAME);
    printf ("Release Date & time: %s - %s\n", MAGIC_PLAYER_VERSION_DATE, MAGIC_PLAYER_VERSION_TIME);
    printf ("Author: %s\n\n", MAGIC_PLAYER_VERSION_AUTHOR);

}

// print the version id
void magic_player_version_print_version_id (void) {

    printf ("\nMagic Player Version ID: %s\n", MAGIC_PLAYER_VERSION);

}

// print the version name
void magic_player_version_print_version_name (void) {

    printf ("\nMagic Player Version: %s\n", MAGIC_PLAYER_VERSION_NAME);

}