#include "http_client.h"

static int inited = 0;

int http_client_init(http_client_t *http_client, write_cb_t *write_cb, void *userp)
{
    if (!inited) {
        curl_global_init(CURL_GLOBAL_NOTHING);
        inited = 1;
    }

    http_client->handle = curl_easy_init();
    if (!http_client->handle) {
        return -1;
    }
    curl_easy_setopt(http_client->handle, CURLOPT_WRITEFUNCTION, write_cb);
    if (userp) {
        curl_easy_setopt(http_client->handle, CURLOPT_WRITEDATA, userp);
    }
    return 0;
}

void http_client_cleanup(http_client_t *http_client)
{
    curl_easy_cleanup(http_client->handle);
    if (inited) {
        curl_global_cleanup();
    }
}

int http_client_make_get_request(const http_client_t *http_client, const char *url)
{
    if (!url) {
        return -1;
    }
    curl_easy_setopt(http_client->handle, CURLOPT_URL, url);
    curl_easy_perform(http_client->handle);
    return 0;
}

int http_client_make_post_request(const http_client_t *http_client, const char *url, void *data, size_t data_len)
{
    if (!url) {
        return -1;
    }

    curl_easy_setopt(http_client->handle, CURLOPT_URL, url);
    if (data) {
        curl_easy_setopt(http_client->handle, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(http_client->handle, CURLOPT_POSTFIELDSIZE, data_len);
    }
    curl_easy_perform(http_client->handle);
    return 0;
}
