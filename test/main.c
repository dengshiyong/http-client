#include <stdio.h>
#include <stdlib.h>

#include "http_client.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }
    httpc_make_get_request(argv[1]);
    return EXIT_SUCCESS;
}
