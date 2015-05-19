#pragma once
#include <curl/curl.h>

typedef struct http_client_t {
    CURL *handle;
} http_client_t;

typedef size_t (write_cb_t)(void *, size_t, size_t, void *);

int http_client_init(http_client_t *http_client);
void http_client_cleanup(http_client_t *http_client);

int http_client_make_get_request(const http_client_t *http_client, const char *url,
        write_cb_t *write_cb, void *userp, int *http_code);
int http_client_make_post_request(const http_client_t *http_client, const char *url,
        void *data, size_t data_len, write_cb_t *write_cb, void *userp, int *http_code);

const char *http_client_strerror(int rc);
