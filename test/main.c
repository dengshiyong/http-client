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
    http_client_init(&http_client);

    int http_code = 0;
    int rc = http_client_make_get_request(&http_client, argv[1], write_data, NULL, &http_code);
    if (rc < 0) {
        fprintf(stderr, "error: %s\n", http_client_strerror(rc));
        return EXIT_FAILURE;
    }
    switch (http_code) {
    case 200:
        break;
    case 404:
        fprintf(stderr, "Not Found\n");
        break;
    default:
        fprintf(stderr, "got response %d\n", http_code);
    }

    rc = http_client_make_post_request(&http_client, argv[1], "hello", 5, write_data, NULL, &http_code);
    if (rc < 0) {
        fprintf(stderr, "error: %s\n", http_client_strerror(rc));
        return EXIT_FAILURE;
    }
    switch (http_code) {
    case 200:
        break;
    case 404:
        fprintf(stderr, "Not Found\n");
        break;
    default:
        fprintf(stderr, "got response %d\n", http_code);
    }

    http_client_cleanup(&http_client);

    return EXIT_SUCCESS;
}
