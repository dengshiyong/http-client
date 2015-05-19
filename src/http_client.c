#include "http_client.h"

int http_client_init(http_client_t *http_client, const char *url, write_cb_t *write_cb, void *userp)
{
    if (!url) {
        return -1;
    }

    http_client->handle = curl_easy_init();
    if (!http_client->handle) {
        return -1;
    }
    curl_easy_setopt(http_client->handle, CURLOPT_URL, url);
    curl_easy_setopt(http_client->handle, CURLOPT_WRITEFUNCTION, write_cb);
    if (userp) {
        curl_easy_setopt(http_client->handle, CURLOPT_WRITEDATA, userp);
    }
    return 0;
}

void http_client_cleanup(http_client_t *http_client)
{
    curl_easy_cleanup(http_client->handle);
}

int http_client_make_get_request(const http_client_t *http_client)
{
    curl_easy_perform(http_client->handle);
    return 0;
}
