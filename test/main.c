#include <stdio.h>
#include <stdlib.h>

#include "http_client.h"

static size_t write_data(void *buf, size_t size, size_t nmemb, void *userp)
{
    (void) buf;
    (void) size;
    (void) userp;

    printf("write_data: %ld\n", nmemb);
    return nmemb;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    http_client_t http_client;
    http_client_init(&http_client, write_data, NULL);
    http_client_make_get_request(&http_client, argv[1]);

    return EXIT_SUCCESS;
}
